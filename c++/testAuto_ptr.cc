#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    int *p = new int(1);
    std::cout << "XXXX *p = " << *p << std::endl;
    // If you use auto_ptr to manager p, you do not care when delete p. 
    // it means you do not need delete p.
    auto_ptr<int> ap(p); 
		std::cout << "XXXX ap = " << *ap << std::endl;


    return 0;
}