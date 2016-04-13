#include <iostream>
#include <cstdlib>
#include <dirent.h>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	char aCommand[1024] = "ls *.cc";
	//int i = system(aCommand);

	DIR *pDir;
	char pPath[256] = "/home/xchonxu/test/";
	struct dirent *entry;

	pDir = opendir(pPath);
	if(NULL == pDir)
	{
		std::cout << "Open Dir Failed!!!!" << std::endl;
	}

	int i = 0;
	while(NULL != (entry = readdir(pDir)))
	{
		std::string strFileName = entry->d_name;
		std::cout << "*********************************" << std::endl;
		std::cout << strFileName << std::endl;
		int beginNop = strFileName.find("test");
		std::cout << "beginNOp " << beginNop << std::endl;
		int endNop = strFileName.find(".cc");
		std::cout << "endNOp " << endNop << std::endl;
		std::cout << "*********************************" << std::endl;

		if(0 == beginNop && strFileName.length() == endNop + 3)
		{
			++i;
			std::cout << strFileName << "OK" << std::endl;
		}
	}

	std::cout << i << std::endl;

	char aStrFileCounter[2];
	memset(aStrFileCounter, 0, 2);
	sprintf(aStrFileCounter, "%d", i);
	std::cout << *aStrFileCounter << std::endl;
	std::string aStrTest = "File is : ";
	std::cout << aStrTest + aStrFileCounter << std::endl;


	return 0;
}
