#include <iostream>
#include <Eigen/Dense>
/*
Eigen使用：
 0.环境配置

 1.数据类型
    定义(四种方式，一种通用方式，两种标准方式， 一种动态矩阵方式)：
        Matrix<元素类型, 行数, 列数> m1; // Matrix<double, 5, 3> m1; 通用格式，能声明矩阵和向量
        Matrix，张量大小，元素类型// Matrix3d m2;
        Vector，张量大小，元素类型 //Vector3d v2; 可以直接初始化：Vector3d v2(0.2, 3.6)
        MatrixX元素类型 m(行数，列数) //MatrixXd m3(3,4);
    Eigen类型：
        • Matrix 矩阵
        • Vector 向量
    张量大小：
        • X 表示动态张量，其大小可以在实例化时指定，也可以运行时指定
        • 2 矩阵固定大小2×2   向量规定大小2×1
        • 3 矩阵固定大小3×3   向量规定大小3×1
        • 4 矩阵固定大小4×4   向量规定大小4×1
    元素类型：
        • i -> int
        • f -> float
        • d -> double
        • cf -> complex float
        • cd -> complex double
    动态矩阵和静态矩阵：
        动态矩阵是指其大小在运行时确定，静态矩阵是指其大小在编译时确定
        对于小矩阵（一般大小小于16）的使用固定大小的静态矩阵，它可以带来比较高的效率，
        对于大矩阵（一般大小大于32）建议使用动态矩阵。
 2.基本操作
    实例化：
        上述四种方式(1-2-1)
        标准矩阵：
            MatrixXd::Random(m,n)：创建m×n维double类型的随机数矩阵
            MatrixXd::Constant(m,n,p)：创建m×n维double类型元素全为p的矩阵
            MatrixXd::Zero(m,n)：创建m×n维元素全为0的矩阵
            MatrixXd::Ones(m,n)：创建m×n维元素全为1的矩阵
            MatrixXd::Identity(m,n)：创建m×n维的单位阵
            VectorXd::LinSpaced(size,low,high)：创建一个size长度的从low到high的向量或一维矩阵
    赋值：
        << 整块赋值 列优先赋值
        m(0,0) 单个赋值
    索引：
        m(0,0) 单个索引
    属性获取：
        rows() 获取行数
        cols() 获取列数
        size() 获取行列大小
        resize(a, b) 用于动态数组大小重整
 3.矩阵运算
    Eigen对数据类型敏感，不会自动类型转换(如自动将float转成double)，不同类型数据运算会报错
    3.1 矩阵和向量间运算
        + 相同大小矩阵
        - 相同大小矩阵
        × 矩阵与矩阵 矩阵与标量 向量数乘 向量点乘 向量叉乘
        / 矩阵与标量
    3.2 矩阵自身运算：
        mat.transpose()：转置矩阵。对于矩阵转置，注意不要写成a = a.transpose()，这会导致错误结果(Aliasing Issue)，如果一定需要对原矩阵进行修改，使用a.transposeInPlace()函数。
        mat.inverse()：逆矩阵
        mat.conjugate()：共轭矩阵
        mat.adjoint()：伴随矩阵
        mat.trace()：矩阵的迹
        mat.eigenvalues()：矩阵的特征值
        mat.determinant()：矩阵求行列式的值
        mat.diagonal()：矩阵对角线元素
        mat.sum()：矩阵所有元素求和
        mat.prod()：矩阵所有元素求积
        mat.mean()：矩阵所有元素求平均
        mat.minCoeff()：矩阵所有元素最小值
        mat.minCoeff(&i,&j)：矩阵所有元素最小值的位置，i、j为int类型或为Eigen的Index类型。
        mat.maxCoeff()：矩阵所有元素最大值
        mat.maxCoeff(&i,&j)：矩阵所有元素最大值的位置
        mat.nonZeros()：矩阵中非零元素个数
        mat.squaredNorm()：矩阵(向量)的平方范数，对向量而言等价于其与自身做点积，数值上等于各分量的平方和。
        mat.norm()：矩阵(向量)的平方范数开根号(对于向量即求模长)
        mat.lpNorm<1>()：矩阵(向量)的L1范数
        mat.lpNorm<2>()：矩阵(向量)的L2范数
        mat.lpNorm<Infinity>()：矩阵(向量)的L无穷范数
        mat.lpNorm<p>()：矩阵(向量)的Lp范数
        mat.normalize()：矩阵(向量)的正则化(归一化)，使所有元素的平方和等于1。
        (mat>0).all()：矩阵元素条件判断，mat中所有元素是否都大于0，是返回1，否则返回0。
        (mat>0).any()：矩阵元素条件判断，mat中所有元素是否有大于0的，有返回1，否则返回0。
        (mat>0).count()：矩阵符合条件的元素计数，返回mat中大于0元素的个数。
        mat.colwise()：返回矩阵每列的值
        mat.rowwise()：返回矩阵每行的值
        //以cwise开头的函数也能逐元素处理
        mat.cwiseProduct()对应元素相乘
        mat.cwiseAbs()元素取绝对值
        mat.cwiseSqrt()逐元素开根号
        mat.cwiseMin()将两个矩阵中相应位置的最小值组成一个新矩阵等等
        //块操作
        mat.block(i,j,p,q) 动态尺寸块 大矩阵适用
        mat.block<p,q>(i,j) 静态尺寸块 小矩阵适用
        mat.row()：用于单独取出某一行(可修改)
        mat.col()：用于单独取出某一列(可修改)
        mat.topLeftCorner()：用于取出左上角元素
    3.数组和Matrix
        Map<Matrix<typename Scalar, 行数, int， [RowMajor]> > mat(data, [行数， 列数]); 默认行优先，开启RowMajor后就列优先
    4.Opencv和Matrix
        cv2eigen(img, matrix);  // 调用函数将Mat转成Matrix
        eigen2cv(matrix, modi_img); // 将Matrix转回Mat
 4.Array类型
    定义：
        Array<元素类型, 行数, 列数 > a1;
        Array3d  a2;//对应向量
        Array33d a3;//对应矩阵
        ArrayXd a4(2,3);//对应动态矩阵
    运算：
        + - × /
        arr.abs()：逐元素取绝对值
        arr.sqrt()：逐元素开根号
        arr.pow()：逐元素乘方
        arr1.min(arr2)：将两个Array中相应位置的最小值组成一个新Array
        arr1.max(arr2)：将两个Array中相应位置的最大值组成一个新Array
    与Matrix转换：
        arr = mat.array()
        mat = arr.matrix()
        不能混合运算，只能先转换统一后再运算
5.Quateriond 四元数
    定义：
        08.Eigen::Quaterniond q1(w, x, y, z);// 第一种方式， 直接定义
        08.Eigen::Quaterniond q2(Vector4d(x, y, z, w));// 第二种方式，通过向量
        08.Eigen::Quaterniond q2(Matrix3d(R));// 第三种方式，通过旋转矩阵
    转换：（四元数，旋转矩阵，旋转向量，欧拉角）
        https://blog.csdn.net/hjwang1/article/details/106752766
        q.toRotationMatrix()  四元数转换为旋转矩阵

 */
using namespace std;
using namespace Eigen;

namespace EigenDemo {

    int Init() {
        //初始化 1 - 2 - 1
        Matrix<double, 1, 2> m1;
        m1 << 1, 2;
        Matrix<double, 2, 1> v1;
        v1 << 1, 2;
        Matrix2d m2;
        m2 << 1, 2, 3, 4;
        Vector2d v2;
        v2 << 1, 2;
        MatrixXd m3(3, 4);//也可以MatrixXd m3；

        Matrix3d m4 = MatrixXd::Identity(3, 3);//也可以不是方阵
        cout << "Identity: \n" << m4 << endl;
        //默认会生成随机数，不赋值时

        Matrix2d m;
        //统一赋值，统一访问
        m << 1, 2, 3, 4;
        cout << m << endl;
        //逐个赋值或索引访问
        m(0, 0) = 10;
        cout << m(0, 0) << endl;
    }

    void BasicOperation() {
        //-------------------矩阵属性获取-------------------//
        Matrix<double, 2, 3> m;
        m << 1, 2, 3, 4, 5, 6;
        cout << m << endl;
        cout << m.rows() << endl;
        cout << m.cols() << endl;
        cout << m.size() << endl;

        //---------------------判决矩阵相等-------------------//
        Matrix2d m1, m2;
        m1 << 1, 2, 3, 4;
        m2 << 1.0, 2.0, 3.0, 4.0;
        cout << (m1 != m2) << endl;
        cout << (m1 == m2) << endl;

        //---------------------一些基本函数-------------------//
        //取向量差值的绝对值的最大值
        Vector2d v1(10.001, 1.001);
        Vector2d v2(10.002, 1.003);
        std::cout<<(v1-v2).cwiseAbs().maxCoeff()<<std::endl;
        //取向量差值的绝对值的最大值
        Matrix2d mm1, mm2;
        mm1<< 10, 10.001, 10.002, 10.003;
        mm2<< 10, 10.004, 10.002, 10.003;
        std::cout<<(mm1-mm2).cwiseAbs().maxCoeff()<<std::endl;

        //---------------------块操作-------------------//
        /**
         * 块操作：Block of size (p,q), starting at (i,j)
         * 动态块操作：matrix.block(i,j,p,q);   适用于大矩阵
         * 静态块操作：matrix.block<p,q>(i,j);  适用于小矩阵
         */
        Eigen::MatrixXf m_block(4,4);
        m_block <<  1, 2, 3, 4,
                5, 6, 7, 8,
                9,10,11,12,
                13,14,15,16;
        cout << "Block in the middle" << endl;
        cout << m_block.block<2,2>(1,1) << endl << endl;
        for (int i = 1; i <= 3; ++i) {
            cout << "Block of size " << i << "x" << i << endl;
            cout << m_block.block(0, 0, i, i) << endl << endl;
        }
    }

    int MatrixVectorCompute() {
        //---------------------矩阵和矩阵与运算-------------------//
        MatrixXd m1(3, 2);
        m1 << 4, 5, 8, 3, 5, 0;
        MatrixXd m2 = m1 + MatrixXd::Constant(m1.rows(), m1.cols(), 1.2);
        cout<< "矩阵加矩阵：\n" <<m2 << endl;
        MatrixXd m3 = m1 - MatrixXd::Constant(m1.rows(), m1.cols(), 1.2);
        cout<< "矩阵减矩阵：\n" <<m3 << endl;

        MatrixXd m4(2,3);
        m4 << 1, 1, 1, 1, 1, 1;
        MatrixXd m5 = m1 * m4;
        cout<< "矩阵乘矩阵：\n" <<m5 << endl;
        Vector2d v1;
        v1 << 1, 1;
        MatrixXd m6 = m1 * v1;
        cout<< "矩阵乘向量：\n" <<m6 << endl;

        Vector3d v(1, 2, 3);
        cout << "向量数乘：\n" << v * 3 << endl;
        cout << "向量点乘：\n" << v.dot(v) << endl;
        cout << "向量叉乘：\n" << v.cross(v) << endl;

    }

    int MatrixSelfCompute() {
        //---------------------矩阵自身运算-------------------//
        MatrixXd m(2, 2);
        m << 4, 5, 8, 3;
        cout<< "原始矩阵：\n" <<m << endl;
        cout<< "矩阵转置：\n" <<m.transpose() << endl;
        cout<< "矩阵特征值：\n" <<m.eigenvalues() << endl;

        MatrixXd m1(2, 4);
        m1 << 1, 2, 3, 4, 5, 6, 7, 8;
        Vector2d m2;
        m2 << 1, 2;
        MatrixXd m3 = m1.colwise() + m2;
        cout << m1 << endl;
        cout << m3 << endl;
    }
    int ArrayDemo(){
        //----------------定义-----------------//
        Array<double, 2,3 > a1;
        a1 << 1, 2,3,4,5,6;

        Array3d  a2;
        Array33d a3;
        ArrayXd a4(2,3);


        Array22d a5;
        a5 << 1, 2, 3, 4;
        Array22d a6;
        a6 << 3, 2, 1, 0;
        cout << a5 * a6 << endl;
    }
    int QuaterniondDemo(){
        double w = 1;
        double x = 2;
        double y = 3;
        double z = 4;
        Eigen::Quaterniond q1(w, x, y, z);// 第一种方式
        Eigen::Quaterniond q2(Vector4d(x, y, z, w));// 第二种方式
//        08.Eigen::Quaterniond q2(Matrix3d(R));// 第三种方式,
        cout<<q1.toRotationMatrix()<<endl;
        cout<<(q1.toRotationMatrix() == q2.toRotationMatrix())<<endl;
        q1.toRotationMatrix() == q2.toRotationMatrix();
    }

}

int main() {
//    EigenDemo::Init();
    EigenDemo::BasicOperation();
//    EigenDemo::Compute();
//    EigenDemo::MatrixVectorCompute();
//    EigenDemo::MatrixSelfCompute();
//    EigenDemo::ArrayDemo();
//    EigenDemo::QuaterniondDemo();
}
