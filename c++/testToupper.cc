
#include <iostream>
#include <string>
#include <algorithm>

//using namespace std;

int main(int argc, char **argv)
{

    std::string UtuEncoded = "001D4275199b0800000000046400";
std::cout << "XXXX UtuEncoded = " << UtuEncoded << std::endl;
    transform(UtuEncoded.begin(), UtuEncoded.end(), UtuEncoded.begin(), toupper);
    
    std::cout << "XXXX UtuEncoded = " << UtuEncoded << std::endl;

    return 0;
} 
