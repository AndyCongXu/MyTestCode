#include "testCallChildClassConstruct.hh"
#include <iostream>

using namespace std;

Parent::Parent()
{
    std::cout << "This is Parent construction" << std::endl;
}

Parent::~Parent()
{
    std::cout << "This is Parent destruction" << std::endl;
}

void Parent::testCheck()
{
    std::cout << "This is Parent testCheck()" << std::endl;
}

void Parent::testCallCheck()
{
    testCheck();
}

Child::Child()
{
    std::cout << "This is Child construction" << std::endl;
}

Child::~Child()
{
    std::cout << "This is Child destruction" << std::endl;
}

void Child::testCheck()
{
    std::cout << "This is Child testCheck()" << std::endl;
}


int main(int argc, char **argv)
{
    Parent *theParent = new Parent();
    theParent->testCallCheck();
    delete theParent;

    std::cout << "****************************" << std::endl;
    Parent *theParentForChild = new Child();
    theParentForChild->testCallCheck();
    delete theParentForChild;

    return 0;
}