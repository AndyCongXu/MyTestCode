#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

std::string GetFileName();


std::string g_strFilePath = "~/test/";

int main(int argc, char **argv)
{
	std::string strFileName = GetFileName();
	if(strFileName.empty())
	{
		std::cout << "Get file name failed!" << std::endl;
		return -1;
	}

	strFileName = g_strFilePath + strFileName;
	ofstream fcout(strFileName.c_str());
	cout.rdbuf(fcout.rdbuf());


	std::cout << "Creat file successful!" << std::endl;


    return 0;
}

std::string GetFileName()
{
    std::string aFileName = "fdspm.log";
    time_t aTCurrentTime = time(NULL);
    struct tm *aTBlock = localtime(&aTCurrentTime);
    int aTYear = aTBlock->tm_year + 1900;
    int aTMonth = aTBlock->tm_mon + 1;
    int aTDay = aTBlock->tm_mday;
    char *aTimeBuf = new char(20);
    memset(aTimeBuf, 0, 20);
    sprintf(aTimeBuf, ".%d-%d-%d.log", aTYear, aTMonth, aTDay);
	aFileName = aFileName + aTimeBuf;

	return aFileName;
}

