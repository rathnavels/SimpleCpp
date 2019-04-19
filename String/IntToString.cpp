#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void runIntToString()
{
  int x = -3321;
  string str = "";
  bool isNegative = false;
  if (x < 0)
  {
    isNegative = true;
    x *= -1;
  }
  while (x)
  {
    int modul = x%10;
    //str = char(48 + modul) + str;
    str += char (48 + modul);
    x /= 10;
  }

  if(isNegative)
    str+='-';

  string s = {rbegin(str),rend(str)};

  cout << s;
}

void runStringToInt()
{
  string str = "-27832";
  int answer=0;
  bool isNegative = false;
  for (int i = 0; i < str.size(); i++)
  {
    if(str[i]=='-')
      isNegative = true;
    else
      answer = answer * 10 + (str[i]-48);
  }
  if(isNegative)
    answer *= -1;

  cout << answer;
}


void runIntToString2()
{
  int x = 0;
  stringstream sstr;
  string str;
  bool neg = false;
  if(x<0)
  { 
    neg = true;
    x = abs(x);
  }
  do
  {
    int mod = x %10;
    sstr << char(48+mod);
    x = x/10;
  }while (x);
  if(neg)
    sstr << '-';

  sstr >> str;
  
  std::cout << string{rbegin(str),rend(str)};
}

void runStringToInt2()
{
  string X = "-347";
  int result = 0;
  bool neg = false;
  for (auto itr = X.begin(); itr < X.end(); itr++)
  {
    if (*itr == '-')
    {
      neg = true;
    }
    else
    {
      result =  (result * 10) + *itr-48;
    }
  }
  if(neg) 
    result *= -1;
  std::cout << result;
}

int runStringToInt2(string &X)
{
  //string X = "-347";
  int result = 0;
  bool neg = false;
  for (auto itr = X.begin(); itr < X.end(); itr++)
  {
    if (*itr == '-')
    {
      neg = true;
    }
    else
    {
      result = (result * 10) + *itr - 48;
    }
  }
  if (neg)
    result *= -1;

  return result;
}