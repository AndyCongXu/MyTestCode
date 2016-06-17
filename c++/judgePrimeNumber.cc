//求1000以内的整数，要求各个未都是素数且各个位之和也是素数

#include <iostream>
#include <vector>

using namespace std;

void getEveryDigit(int theIntNumber, std::vector<int>& theVecEveryDigit);
void getSum(int& theIntSum, const std::vector<int>& theVecEveryDigit);
bool judgePrimeNumber(int theIntNumber);
void displayResult(const std::vector<int>& theVecEveryDigit);

int main(int argc, char **argv)
{
    int anIntMax = 1000;
    int anIntSum = 0;
    int aInt = 2;
    bool anIsPrimeNumber = false;

    while(aInt <= anIntMax)
    {
        std::vector<int> aVecEveryDigit;
        anIntSum = 0;
        getEveryDigit(aInt, aVecEveryDigit);
        for(int k = 0; k < aVecEveryDigit.size(); k++)
        {
            if(false == judgePrimeNumber(aVecEveryDigit.at(k)))
            {
                aInt++;
                anIsPrimeNumber = true;
                continue;
            }
        }

        if(anIsPrimeNumber)
        {
            anIsPrimeNumber = false;
            continue;
        }

        getSum(anIntSum, aVecEveryDigit);
        
        if(false == judgePrimeNumber(anIntSum))
        {
            aInt++;
            continue;
        }

        displayResult(aVecEveryDigit);
        aInt++;
    }

    return 0;
}

void getEveryDigit(int theIntNumber, std::vector<int>& theVecEveryDigit)
{
    int j = theIntNumber;
    
    while(true)
    {
        int iQuotient = j / 10;
        int iRemainder  = j %10;
        if(0 == iQuotient)
        {
            theVecEveryDigit.push_back(iRemainder);
            break;
        }

        j = iQuotient;
        theVecEveryDigit.push_back(iRemainder);
    }
}

void getSum(int& theIntSum, const std::vector<int>& theVecEveryDigit)
{
    //std::vector<int>::const_iterator it = theVecEveryDigit.begin();
    auto it = theVecEveryDigit.begin();
    for(; it != theVecEveryDigit.end(); it++)
    {
        theIntSum += *it;
    }

    return ;
}

bool judgePrimeNumber(int theIntNumber)
{
    int i = 2;
    for(; i <= theIntNumber / 2; i++)
    {
        if(0 == theIntNumber % i)
        {
            return false;
        }
    }

    return true;
}

void displayResult(const std::vector<int>& theVecEveryDigit)
{
    int anIntSum = 0;
    //std::vector<int>::const_iterator it = theVecEveryDigit.crbegin();
    auto it = theVecEveryDigit.crbegin();

    std::cout << *it;
    anIntSum += *it;
    ++it;

    for(; it != theVecEveryDigit.crend(); it++)
    {
        std::cout  << " + " << *it;
        anIntSum += *it;
    }
   
    std::cout << " = " << anIntSum << std::endl;
}