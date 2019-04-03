#include<string>
#include<iostream>
#include<sstream>
using namespace std;

// Z <===> 26
// AA <====> 27
// 543 <====> TW

void runSpreadsheetEncoding()
{
  string X = "ZZZZ";
  int incr=0;
  int Number = 0;
  for (auto itr = X.rbegin(); itr < X.rend(); itr++)
  {
    Number = Number + (*itr-64) * pow(26, incr++);
  }
  std::cout << Number;
}

void runReverseSpreadsheetEncoding()
{
  int X = 475254;
  string str;
  while (X)
  {
    auto mod = X % 26;
    if(mod!=0)
    { 
      str += 64 + mod;
      X = X / 26;
    }
    else
    {
      str += 'Z';
      X = (X-26) / 26;
    }
    //str += (mod != 0) ? 64 + mod : 64 + 26;
    
  }
  std::cout << string{rbegin(str), rend(str)};
}