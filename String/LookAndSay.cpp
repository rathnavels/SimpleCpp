#include<string>
#include<iostream>
#include<sstream>
using namespace std;

// 4, 14, 1114, 3114, 132114, 1113121114

string IntToString(int num)
{
  string str;
  
  while (num)
  {
    auto mod = num % 10;
    str += '0' + mod;
    num = num/10;
  }
  return {rbegin(str),rend(str)};
}

string doThis(string &str)
{
  auto itr = str.begin();
  string retStr;
  while (itr != str.end())
  {
    int count = 1;
      while(itr + 1 != str.end() && *itr == *(itr+1))
      { 
        count++;
        itr++;
      }
    retStr += to_string(count);
    retStr += *itr;

   itr++;
  }
  return retStr;
}

void runLookAndSay()
{
  int n = 432;
  string s = IntToString(n);
  
  for (int i=0; i<3; i++)
  {
    s = doThis(s);
  }
  std::cout << s;
}