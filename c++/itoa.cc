#include <iostream>
#include <string>

using namespace std;

std::string ITOA(int theNumber)
{
	char aTmpStr[16];
    memset(aTmpStr, 0, 16);
	sprintf(aTmpStr, "%x", theNumber);
	std::string aStr = aTmpStr;

	return aStr;
}

int main(int argc, char **argv)
{
    int i = 17;
    std::cout << "ITOA(" << i << ") = " << ITOA(i) << std::endl;

   return 0;
}