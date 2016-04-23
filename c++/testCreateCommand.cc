#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	const char *aLogDir = getenv("OLDPWD"); // You mnust use 'const char *', you must not 'char *'. The detail infor, you can refer construction function of std::string
	std::cout << aLogDir << std::endl;
	std::string aStrFile(aLogDir);
	aStrFile += "/test/";
	aStrFile += "testCreateCommand.cc";
	std::cout << aStrFile << std::endl;
    char aStrCommand[256] = "";
	strcpy(aStrCommand, "ls -l ");
	strcat(aStrCommand, aStrFile.c_str());
	system(aStrCommand);

	return 0;
}
