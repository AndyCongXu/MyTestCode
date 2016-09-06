#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

    //��ͨ��ָ��
    int a = 2;
    int *p = &a;

    std::cout << "*******��ͨ��ָ��**********" << std::endl;
    std::cout << "&a = " << &a << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "*p = " << *p << std::endl;

    //��������ָ�룬ָ��ָ��int�͵�����
    int *p1[3];
    int m[3] = {1, 2, 3};

    p1[0] = &m[0];
    p1[1] = &m[1];
    p1[2] = &m[2];

    std::cout << std::endl;
    std::cout << "*******��������ָ�룬ָ��ָ��int�͵�����**********" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "&m[" << i << "] = " << &m[i] << std::endl;
        std::cout << "p1[" << i << "] = " << p1[i] << std::endl;
        std::cout << "m[" << i << "] = " << m[i] << std::endl;
        std::cout << "*p1[" << i << "] = " << *p1[i] << std::endl;
    }

    //����һ�����飬Ȼ����һ��ָ��ָ���������
    int (*p4)[3];
    p4 = &m;

    std::cout << std::endl;
    std::cout << "*******����һ�����飬Ȼ����һ��ָ��ָ���������**********" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        std::cout << "&m[" << i << "] = " << &m[i] << std::endl;
        std::cout << "&(*p4)[" << i << "] = " << &(*p4)[i] << std::endl;
        std::cout << "m[" << i << "] = " << m[i] << std::endl;
        std::cout << "(*p4)[" << i << "] = " << (*p4)[i] << std::endl;
    }

    //����ָ��
    int d = 4;
    int *pd = &d;
    int **ppd = &pd;
    
    std::cout << std::endl;
    std::cout << "*******����ָ��*********" << std::endl;
    std::cout << "---------ֵ------------" << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "*pd = " << *pd << std::endl;  
    std::cout << "**ppd = " << **ppd << std::endl;

    std::cout << "--------ָ��ĵ�ַ--------------" << std::endl;
    //*ppd == pd == &d
    std::cout << "&d = " << &d << std::endl;
    std::cout << "pd = " << pd << std::endl; //ָ��ָ��ĵ�ַ
    std::cout << "*ppd = " << *ppd << std::endl;//����ָ��ָ��ĵ�ַ

    std::cout << "----------ָ�뱾��ĵ�ַ------------" << std::endl;
    std::cout << "&pd = " << &pd << std::endl; //ָ�뱾��ĵ�ַ
    std::cout << "&(*ppd) = " << &(*ppd) << std::endl; // ���ȣ�*ppd��
    std::cout << "&(*pd) = " << &(*pd) << std::endl;
    std::cout << "&ppd = " << &ppd << std::endl; //ָ�뱾��ĵ�ַ




    return 0;
}