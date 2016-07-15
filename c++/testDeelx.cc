#include <iostream>
#include "deelx.h"
#include <memory>

using namespace std;

//If you want to know the detail information about deelx,
//You can refer the ../Reference Document/deelx_zh.chm.

int main(int argc, char **argv)
{
    CRegexpT<char> pRegExp("((\\+?[0-9]+,)*(\\+?[0-9]+))?");
    //std::auto_ptr<char> ptrRegExp(pRegExp);
    char *testStr = "+12,2,+36";

    MatchResult anIntResult = pRegExp.MatchExact(testStr);
    std::cout << "XXXX anIntResult = " << anIntResult.IsMatched() << std::endl;

    char *testStr1 = "";

    anIntResult = pRegExp.MatchExact(testStr1);
    std::cout << "XXXX anIntResult = " << anIntResult.IsMatched() << std::endl;


    return 0;
}