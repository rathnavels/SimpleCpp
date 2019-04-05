#include<string>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;

// Roman Numeral Conversion to Number
std::map<char, int> romanMap;
void initiate()
{
  romanMap.insert(std::pair<char, int>('I', 1));
  romanMap.insert(std::pair<char, int>('V', 5));
  romanMap.insert(std::pair<char, int>('X', 10));
  romanMap.insert(std::pair<char, int>('L', 50));
  romanMap.insert(std::pair<char, int>('C', 100));
  romanMap.insert(std::pair<char, int>('D', 500));
  romanMap.insert(std::pair<char, int>('M', 1000));
}

void runRomanNumeral(string romanStr)
{

  initiate();
  //string romanStr = "XCIX";
  int sum = 0;
  if(romanStr.size()==1)
    sum = romanMap[romanStr[0]];
  for (int i = 0; i < romanStr.size() - 1; i++)
  {
    if(romanMap[romanStr[i]]<romanMap[romanStr[i+1]])
    { 
      sum += romanMap[romanStr[i + 1]] - romanMap[romanStr[i]];
      i++;
    }
    else
      sum += romanMap[romanStr[i]];
  }

  std::cout << sum << endl;
  
}

void runRomanNumeral2(string romanStr)
{
  //string romanStr = "XCIX";
  initiate();
  int sum = romanMap[romanStr.back()];

  for (int i = romanStr.length() - 2; i >= 0; i--)
  {
    if (romanMap[romanStr[i]] < romanMap[romanStr[i + 1]])
      sum -= romanMap[romanStr[i]];
    else
      sum += romanMap[romanStr[i]];
  }
  std::cout << sum << endl;
}


void runRomanNumeralMain()
{
  string str = "MDCXCIV";
  runRomanNumeral(str);
  runRomanNumeral2(str);
}