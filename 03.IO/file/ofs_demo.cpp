#include <fstream>

#include "all.h"

/**
#include <fstream> 包含三个文件流类：
ofstream         //文件写操作 内存写入存储设备
ifstream         //文件读操作，存储设备读区到内存中
fstream          //读写操作，对打开的文件可进行读写操作

1.打开文件
open(const char * filename， mode)函数
    filename:文件名
    mode:文件读写模式
        ios::in     为输入(读)而打开文件
        ios::out	为输出(写)而打开文件
        ios::ate	初始位置：文件尾
        ios::app	所有输出附加在文件末尾
        ios::trunc	如果文件已存在则先删除该文件
        ios::binary	二进制方式
2.关闭文件
close()函数：
    使用文件后必须关闭文件，便于当前流关联其他文件，当前文件被其他流使用
3.文本文件读写
写： os << "txt" <<std::endl;
读： os >> a;
    os.getline(buffer,10);

eof()函数：
    如果读文件到达文件末尾，返回true。

获得/设置流指针：
ifstream，get pointer指向下一个将被读取的元素。
ofstream, put pointer指向写入下一个元素的位置。
fstream,  同时继承了get 和 put

tellg()获得当前get流指针的位置

tellp()获得当前put流指针的位置

seekg(pos)设置get流指针
    seekg(2)移动到2
    seekg(2,ios::beg)以开始为单位移动2
seekp(pos)设置put流指针

pos:
ios::beg	从流开始位置计算的位移
ios::cur	从流指针当前位置开始计算的位移
ios::end	从流末尾处开始计算的位移

peek() 读取get指针下一个字符，指针不动

4.二进制文件读写
write( char * buffer, 100);
read( char * buffer, 100);

 */

using namespace std;
namespace ofs_demo {

//文本读
int fileWrite() {
  ofstream os("file_write.txt", ios::app);
  if (os.is_open()) {
    int cnt = 3;
    while (cnt--) {
      os << "this is the num " << cnt << endl;
    }
    os.close();
  }
}

//文本写
int fileRead() {
  char buf[1024];
  ifstream is("file_write.txt");
  if (!is.is_open()) {
    return -1;
  }
  while (!is.eof()) {
    is.getline(buf, 100);  // is>>a>>b>>c
    cout << buf << endl;
  }
  is.close();
}

const char* fileName = "file_write_binary.dat";
//二进制读
int fileWriteBinary() {
  ofstream os(fileName, ios::app | ios::binary);
  if (!os.is_open()) {
    return -1;
  }

  char* buf;
  for (int i = 0; i < 10; i++) {
      buf[i] = (char)i;
  }

  os.write(buf,10);
  os << "this is the num " << 10 << endl;
  os.close();
}
//二进制写
int fileReadBinary() {

  ifstream is(fileName,ios::binary);
  if (!is.is_open()) {
    return -1;
  }
  is.seekg(0,ios::end);//get指针切换到end,以end为基地址移动0
  int len = is.tellg();//获取从0到当前get指针的偏移量
  cout<<len<<endl;
  is.seekg(0,ios::beg);

  char buf[len];

  is.read(buf,len);
  cout<<buf<<endl;
  is.close();
}

int test() {
//  fileWrite();
//  fileRead();
  fileWriteBinary();
  fileReadBinary();
  return 0;
}
}  // namespace ofs_demo
