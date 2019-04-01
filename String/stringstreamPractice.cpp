#include<string>
#include<sstream>
#include<iostream>
using namespace std;

void reverseString(string &str)
{
  for (int i = 0, j=str.size()-1; i < str.size() / 2; i++,j--)
  {
     char temp = str[i];
     str[i] = str[j];
     str[j] = temp;
  }
}

void runStringStream()
{
  string sentence = "Lets take leetcode contest";
  string word;
  std::stringstream sStream(sentence);
  string returnString = "";

  while (sStream >> word)
  {
    reverse(word.begin(), word.end());
    returnString += word;
    returnString += " ";
  }

  returnString.pop_back();

  cout <<  returnString;
  
}