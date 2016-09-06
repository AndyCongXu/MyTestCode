/*
* 静态数据成员 和 普通数据成员 的区别
* 作用：
* 静态数据成员是这个类的所有对象共享。
*
* 声明：
* 普通成员变量： int a;
* 静态数据成员： static int b;
*
* 初始化：
* 静态数据成员可以在类外初始化。（不管是private 还是 public），普通数据成员不可以。
* 静态数据成员不可以通过构造函数来初始化，但是普通数据成员可以。
*
* 存储区域：
* 普通成员需要被实例化后才会分配内存， 访问方式为 objcet.a（前提是public）
* 静态成员存储在内存中，可以直接使用 object::b 来访问
*
* 调用：
* 一般来说静态数据成员只能使用静态成员函数来调用，不建议通过
* 普通成员函数来调用静态数据成员。相对应的，非静态数据成员也
* 也只能通过非静态成员函数调用。 虽然可以通过方法来实现静态
* 成员函数调用非静态数据成员，但是不建议这么做。
*
*
* 静态成员函数 和 普通成员函数 的区别
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
    * error C2438: “myStrTeacherName”: 无法通过构造函数初始化静态类数据
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

// 静态成员的另一种初始化
std::string TestStaticFun::myStrTeacherName = "Andy";

int main(int argc, char **argv)
{



    return 0;
}