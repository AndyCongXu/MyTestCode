/*
* ��̬���ݳ�Ա �� ��ͨ���ݳ�Ա ������
* ���ã�
* ��̬���ݳ�Ա�����������ж�����
*
* ������
* ��ͨ��Ա������ int a;
* ��̬���ݳ�Ա�� static int b;
*
* ��ʼ����
* ��̬���ݳ�Ա�����������ʼ������������private ���� public������ͨ���ݳ�Ա�����ԡ�
* ��̬���ݳ�Ա������ͨ�����캯������ʼ����������ͨ���ݳ�Ա���ԡ�
*
* �洢����
* ��ͨ��Ա��Ҫ��ʵ������Ż�����ڴ棬 ���ʷ�ʽΪ objcet.a��ǰ����public��
* ��̬��Ա�洢���ڴ��У�����ֱ��ʹ�� object::b ������
*
* ���ã�
* һ����˵��̬���ݳ�Աֻ��ʹ�þ�̬��Ա���������ã�������ͨ��
* ��ͨ��Ա���������þ�̬���ݳ�Ա�����Ӧ�ģ��Ǿ�̬���ݳ�ԱҲ
* Ҳֻ��ͨ���Ǿ�̬��Ա�������á� ��Ȼ����ͨ��������ʵ�־�̬
* ��Ա�������÷Ǿ�̬���ݳ�Ա�����ǲ�������ô����
*
*
* ��̬��Ա���� �� ��ͨ��Ա���� ������
*
*
*/

#include <iostream>
#include <string>

using namespace std;

class TestStaticFun
{
public:
    /*
    * error C2438: ��myStrTeacherName��: �޷�ͨ�����캯����ʼ����̬������
    */
    //TestStaticFun():myStrName(""), myStrAge("0"), myStrTeacherName(""){}
    //TestStaticFun(std::string theStrName, std::string theStrAge, std::string theStrTeacherName):myStrName(theStrName), myStrAge(theStrAge), myStrTeacherName(theStrTeacherName){}

    virtual ~TestStaticFun(){}

    void setName(const std::string& theStrName){myStrName = theStrName;}
    std::string getName(){return myStrName;}

    void setAge(const std::string& theStrAge){myStrAge = theStrAge;}
    std::string getAge(){return myStrAge;}
    static void setTeacherName(const std::string& theStrTeacherName){myStrTeacherName = theStrTeacherName;}
    static std::string getTeacherName(){return myStrTeacherName;}

private:
    std::string myStrName;
    std::string myStrAge;
    static std::string myStrTeacherName;
};

// ��̬��Ա����һ�ֳ�ʼ��
std::string TestStaticFun::myStrTeacherName = "Andy";

int main(int argc, char **argv)
{



    return 0;
}