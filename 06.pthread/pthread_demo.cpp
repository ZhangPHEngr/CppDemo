#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include "all.h"

/**
 *pthread:多线程
 *      #include<pthread.h>
 *      线程用于创建并行任务，锁用于解决并行任务间的资源冲突和同步。
 * 1.线程相关
 *      1.1 线程创建启动：
 *          int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
 *      1.2 线程资源注销：
 *          int pthread_detach(pthread_t tid);//设置线程为可分离，也即执行完自动注销线程资源，在子线程中使用pthread_detach(pthread_self());
 *          int pthread_join(pthread_t tid, void **status);//设置线程结束后合入主线程，这也即手动注销线程资源，可以通过status获得线程返回值；
 *      1.3 线程注销：
 *          void  pthread_exit（void  *retval）;//写在线程内部，用于传递返回值
 * 2.锁相关
 *      2.1 互斥锁
 *          概念：锁唯一，同一时间只有一个线程能获得该锁的使用权，期间其他线程阻塞等待；
 *               条件信号量进入wait状态后会释放锁，并阻塞当前线程直到条件信号量变化（被signal触发）
 *          基本流程：
 *              pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//初始化互斥锁
 *              pthread_cond_t cond = PTHREAD_COND_INITIALIZER;//初始化条件变量
 *
 *              pthread_mutex_lock(&mutex);//锁住互斥量
 *              pthread_cond_signal(&cond);//发送信号量 跟wait函数不在同一个线程中
 *              pthread_mutex_unlock(&mutex);//解锁互斥量
 *
 *              pthread_mutex_lock(&mutex);//锁住互斥量
 *              pthread_cond_wait(&cond,&mutex);//阻塞线程，等待条件变量变化，同时解锁互斥量
 *              pthread_mutex_unlock(&mutex);//解锁互斥量
 *
 *              pthread_mutex_destroy(&mutex);//销毁互斥锁
 *              pthread_cond_destroy(&cond);//销毁条件变量
 *      2.2 自旋锁
 *          概念：自旋锁与互斥量功能一样，唯一一点不同的就是互斥量阻塞后休眠让出cpu，而自旋锁阻塞后不会让出cpu，会一直忙等待，直到得到锁。
 *      2.3 读写锁
 *          概念：读写锁与互斥量类似，不过读写锁允许更改的并行性，也叫共享互斥锁。
 *              互斥量要么是锁住状态，要么就是不加锁状态，而且一次只有一个线程可以对其加锁。读写锁可以有3种状态：读模式下加锁状态、写模式加锁状态、不加锁状态。
 *              一次只有一个线程可以占有写模式的读写锁，但是多个线程可以同时占有读模式的读写锁（允许多个线程读但只允许一个线程写）。
 *3. 参考：
 * pthread详解：https://blog.csdn.net/daaikuaichuan/article/details/82950711
 *             https://blog.csdn.net/u013894427/article/details/83827173
 * pthread_join()与pthread_detach()的区别：https://blog.csdn.net/weibo1230123/article/details/81410241
 *
 */

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int i = 1;

namespace pthread_demo {

void* threadFunc1(void* args){

    for(i=1;i<=6;i++)
    {
        printf("thread1: Line: %d, i = %d\n", __LINE__, i);
        pthread_mutex_lock(&mutex);/*锁住互斥量*/
        printf("thread1: lock %d\n", __LINE__);
        if(i%3==0)
        {
            printf("thread1:signal 1 %d\n", __LINE__);
            pthread_cond_signal(&cond);/*条件改变，发送信号，通知t_b进程*/
            printf("thread1:signal 2 %d\n", __LINE__);
            printf("%s will sleep 1s in Line: %d \n", __FUNCTION__, __LINE__);
            sleep(1);
        }
        pthread_mutex_unlock(&mutex);/*解锁互斥量*/
        printf("thread1: unlock %d\n", __LINE__);
        printf("%s will sleep 1s in Line: %d \n\n", __FUNCTION__, __LINE__);
        sleep(1);
    }

}
void* threadFunc2(void* args){


    while(i<6)
    {
        printf("thread2: Line: %d, i = %d\n", __LINE__, i);
        pthread_mutex_lock(&mutex);
        printf("thread2: lock %d\n", __LINE__);
        if(i%3!=0)
        {
            printf("thread2: wait 1 %d\n", __LINE__);
            pthread_cond_wait(&cond,&mutex);/*解锁mutex，并等待cond改变*/
            printf("thread2: wait 2 %d\n", __LINE__);
        }
        pthread_mutex_unlock(&mutex);
        printf("thread2: unlock %d\n", __LINE__);
        printf("%s will sleep 1s in Line: %d \n\n", __FUNCTION__, __LINE__);
        sleep(1);
    }

}

void main(){
    pthread_t pid1;
    pthread_t pid2;
    pthread_create(&pid1,NULL,threadFunc1,NULL);
    pthread_create(&pid2,NULL,threadFunc2,NULL);
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}

}
