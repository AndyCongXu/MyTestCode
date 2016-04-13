#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    std::list<std::string> aFileList;

	std::string aStrFileName = "AGPS_20160406_1.log";
	aFileList.push_back(aStrFileName);

    aStrFileName = "AGPS_20160406_2.log";
	aFileList.push_back(aStrFileName);

    aStrFileName = "AGPS_20160406_3.log";
	aFileList.push_back(aStrFileName);

    aStrFileName = "AGPS_20160406_4.log";
	aFileList.push_back(aStrFileName);

    aStrFileName = "AGPS_20160406_34.log";
	aFileList.push_back(aStrFileName);
    aStrFileName = "AGPS_20160406.log";
	aFileList.push_back(aStrFileName);

    //aStrFileName = "AGPS_20160406_a.log";
	//aFileList.push_back(aStrFileName);

	aFileList.sort();
	std::list<int> aNumberList;
	std::list<string> aNumberStrList;

	std::list<string>::iterator it = aFileList.begin();
	for(; it != aFileList.end(); it++)
	{
		//std::cout << *it << std::endl;
	    std::string aMaxNumber = *it;
     	std::cout << "aMaxNumber = " << aMaxNumber << std::endl;
    	int anIntBegin = aMaxNumber.find("AGPS_20160406_");
    	int anIntEnd = aMaxNumber.find(".log");
    	std::cout << "anIntBegin = " << anIntBegin << std::endl;
    	std::cout << "anIntEnd = " << anIntEnd << std::endl;
    	std::string aMaxNum = aMaxNumber.substr(14, anIntEnd - 14);
    	std::cout << "aMaxNum = " << aMaxNum << std::endl;
		aNumberStrList.push_back(aMaxNum);
    	int i = atoi(aMaxNum.c_str());
    	std::cout << "i = " << i << std::endl;
		aNumberList.push_back(i);
	}

	aNumberList.sort();
	std::cout << aNumberList.back() << std::endl;

	aNumberStrList.sort();
	std::cout << aNumberStrList.back() << std::endl;
	

	return 0;
}
