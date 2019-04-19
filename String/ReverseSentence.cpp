#include<string>
#include<iostream>
#include<sstream>
using namespace std;

void runReverseSentence()
{
  string str = "Alice likes Bobby man";
  stringstream sstr(str);
  string word;
  str = "";
  while (sstr >> word)
  {
    word += " ";
    str.insert(0, word);
  }
  str.pop_back();

  std::cout << str; 
}

void runReverseSentence2()
{
  string str = "Alice likes Bobby man";
  reverse(str.begin(),str.end());

  size_t start = 0, finish;
 
  while ((finish = str.find(" ",start)) != string::npos)
  {
    reverse(begin(str)+start, begin(str)+finish);
    start = finish + 1;
  }
  
  reverse(begin(str) + start, end(str));
  std::cout << str;
}