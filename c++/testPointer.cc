#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

    //普通的指针
    int a = 2;
    int *p = &a;

    std::cout << "*******普通的指针**********" << std::endl;
    std::cout << "&a = " << &a << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "*p = " << *p << std::endl;

    //定义三个指针，指针指向int型的数据
    int *p1[3];
    int m[3] = {1, 2, 3};

    p1[0] = &m[0];
    p1[1] = &m[1];
    p1[2] = &m[2];

    std::cout << std::endl;
    std::cout << "*******定义三个指针，指针指向int型的数据**********" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "&m[" << i << "] = " << &m[i] << std::endl;
        std::cout << "p1[" << i << "] = " << p1[i] << std::endl;
        std::cout << "m[" << i << "] = " << m[i] << std::endl;
        std::cout << "*p1[" << i << "] = " << *p1[i] << std::endl;
    }

    //定义一个数组，然后用一个指针指向这个数组
    int (*p4)[3];
    p4 = &m;

    std::cout << std::endl;
    std::cout << "*******定义一个数组，然后用一个指针指向这个数组**********" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "&m[" << i << "] = " << &m[i] << std::endl;
        std::cout << "&(*p4)[" << i << "] = " << &(*p4)[i] << std::endl;
        std::cout << "m[" << i << "] = " << m[i] << std::endl;
        std::cout << "(*p4)[" << i << "] = " << (*p4)[i] << std::endl;
    }

    //二级指针
    int d = 4;
    int *pd = &d;
    int **ppd = &pd;
    
    std::cout << std::endl;
    std::cout << "*******二级指针*********" << std::endl;
    std::cout << "---------值------------" << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "*pd = " << *pd << std::endl;  
    std::cout << "**ppd = " << **ppd << std::endl;

    std::cout << "--------指向的地址--------------" << std::endl;
    //*ppd == pd == &d
    std::cout << "&d = " << &d << std::endl;
    std::cout << "pd = " << pd << std::endl; //指针指向的地址
    std::cout << "*ppd = " << *ppd << std::endl;//二级指针指向的地址

    std::cout << "----------指针本身的地址------------" << std::endl;
    std::cout << "&pd = " << &pd << std::endl; //指针本身的地址
    std::cout << "&(*ppd) = " << &(*ppd) << std::endl; // 首先（*ppd）
    std::cout << "&(*pd) = " << &(*pd) << std::endl;
    std::cout << "&ppd = " << &ppd << std::endl; //指针本身的地址




    return 0;
}