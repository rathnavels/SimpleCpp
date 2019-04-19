#include<string>
#include<iostream>
#include<sstream>
using namespace std;

bool IsChar(char c)
{
  //cout << c << endl;
  if(c >= 65 && c <90 || c >= 97 && c <= 122)
    return true;
  
  return false;
}

void runPalindromeString()
{
bool PALIN = true;

string str1 ="A man, a plan, a canal, Panama.";
string str2 ="Able was I, ere I saw Elba!";
string str = "Ray a Rayar";
auto itr1 = str.begin();
auto itr2 = str.end();
itr2--;

  for (; itr1 < itr2; itr1++, itr2--)
  {
    while(!IsChar(*itr1))
     { itr1++; }
    while (!IsChar(*itr2))
     { itr2--; }
    if(*itr1 == *itr2 || *itr1 - 32 == *itr2 || *itr1 == *itr2-32)
      continue;
    else
    {
      PALIN = false;
      break;
    }
  }

  if(PALIN)
    cout << "Yes Bro!!!";
  else
    cout << "No Bro!!!";

}