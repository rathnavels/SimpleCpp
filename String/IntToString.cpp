#include<string>
#include<iostream>
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
    str +=  '0' + modul;
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