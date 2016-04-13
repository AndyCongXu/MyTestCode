#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <cstdio>
#include <ctime>
//#include <rw/re.h>
//#include <rw/rstream.h>
//#include <rw/cstring.h>

using namespace std;

int main(int argc, char **argv)
{
	std::string aFileName = "/home/xchonxu/test/test.py";
	struct stat aStatBuffer;
	memset(&aStatBuffer, 0, sizeof(aStatBuffer));
	int aResult = stat(aFileName.c_str(), &aStatBuffer);
	std::cout << "aResult = " << aResult << std::endl;
	time_t aFileLastModifiedTime = aStatBuffer.st_mtime;
	if(0 == aResult)
	{
		std::cout << aFileLastModifiedTime << std::endl;
		struct tm *timeInfo = localtime(&aFileLastModifiedTime);
		std::cout << timeInfo->tm_year + 1900 << std::endl;


	}

	FILE *aLogFile = fopen(aFileName.c_str(), "a+");
	memset(&aStatBuffer, 0, sizeof(aStatBuffer));
    aResult = stat(aFileName.c_str(), &aStatBuffer);
	std::cout << aStatBuffer.st_mtime << std::endl;

	std::string aStrTest = "\n**** LOG HAS REACHED MAX SIZE ****\n\n Logging is continued in new file";
	std::cout << aStrTest << std::endl;
	//fprintf(aLogFile, "%s", aStrTest.c_str());
	//fflush(aLogFile);

	bool aIsToday = false;                                                                                                
	struct tm *timeFileInfo = localtime(&aFileLastModifiedTime);                                                           
	time_t aTmToday;                                                                                                       
	aTmToday = time(NULL);
	struct tm *timeTodayInfo = localtime(&aTmToday);                                                                       

	std::cout << "" << timeFileInfo->tm_year << std::endl;
	std::cout << "" << timeFileInfo->tm_mon << std::endl;
	std::cout << "" << timeFileInfo->tm_mday << std::endl;
	std::cout << "" << timeTodayInfo->tm_year << std::endl;
	std::cout << "" << timeTodayInfo->tm_year << std::endl;
	std::cout << "" << timeTodayInfo->tm_year << std::endl;

	if(timeTodayInfo->tm_year < timeFileInfo->tm_year                                                                      
				     || timeTodayInfo->tm_mon < timeFileInfo->tm_mon                                                                   
					      || timeTodayInfo->tm_mday < timeFileInfo->tm_mday)                                                                
	{                                                                                                                      
		    aIsToday = false;                                                                                                  
			std::cout << "ddf" << std::endl;
	}     

//	RWCString aRWCStrTest = "sdklfj";
//	std::cout << aRWCStrTest << std::endl;

    //aLogFile.close();	

	fclose(aLogFile);


    return 0;
}
