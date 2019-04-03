#include<string>
#include<iostream>
#include<sstream>
using namespace std;

int runStringToInt2(string &X);

int convertBaseToDecimal(int number, int base)
{
int cNum = 0;
int incr = 0;

  while (number)
  {
    auto mod = number%10;
    cNum = cNum + mod * pow(base, incr++);
    number /= 10;
  }
  return cNum;
}

string convertB1ToB2(int numberb1, int base)
{
 
  string strb2;
  
  while (numberb1)
  {
    auto mod = numberb1 % base;
    strb2 += (mod<10) ? '0' + mod : 'A' + (mod-10);
    numberb1 = numberb1 / base;
  }
  
  return {rbegin(strb2),rend(strb2)};
}

void runBaseConversion()
{
  string str = "2345";
  int b1 = 7;
  int b2 = 13;
  
  int number = runStringToInt2(str);
  int numberb1 = convertBaseToDecimal(number, b1);
  string numberb2 = convertB1ToB2(numberb1, b2);
  
  cout << numberb2;
}