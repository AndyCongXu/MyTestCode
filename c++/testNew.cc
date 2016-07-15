#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        int *p = new int[1000000];
    }
    catch(std::bad_alloc& e)
    {
        std::cout << "XXXX New p failed" << std::endl;
        return -1;
    }

    //If you do not want to use try check new failed, you can use new as below:
    int *p1 = new (std::nothrow) int;
    if(NULL == p1)
    {
        std::cout << "XXXX New p1 failed" << std::endl;
        return -1;
    }


    return 0;
} 