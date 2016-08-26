#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    float f = 6.64;
    std::cout << "round(" << f << ") = " << round(f) << std::endl;
    std::cout << "floor(" << f << ") = " << floor(f) << std::endl;
    std::cout << "ceil(" << f << ") = " << ceil(f) << std::endl;
    std::cout << "trunc(" << f << ") = " << trunc(f) << std::endl;

    f = 6.54;
    std::cout << "round(" << f << ") = " << round(f) << std::endl;
    std::cout << "floor(" << f << ") = " << floor(f) << std::endl;
    std::cout << "ceil(" << f << ") = " << ceil(f) << std::endl;
    std::cout << "trunc(" << f << ") = " << trunc(f) << std::endl;

    f = 6.45;
    std::cout << "round(" << f << ") = " << round(f) << std::endl;
    std::cout << "floor(" << f << ") = " << floor(f) << std::endl;
    std::cout << "ceil(" << f << ") = " << ceil(f) << std::endl;
    std::cout << "trunc(" << f << ") = " << trunc(f) << std::endl;

    return 0;
}