#include<iostream>
#include<string>

int x=1;

//-----------------------------------------------------------------------------
// checkPalindrome
//-----------------------------------------------------------------------------
bool checkPalindrome(std::string str)
{

  for(int i=0,j=str.length()-1; i<str.length()/2; i++, j--)  
  {
    if(str[i]==str[j])
      continue;
    else
      return false;
  }

  return true;
}

//-----------------------------------------------------------------------------
// checkPalindromeRecursion
//-----------------------------------------------------------------------------
bool checkPalindromeRecursion(std::string str)
{
  if(str.length() <= 1)
    return true;

  if(str[0] != str[str.length()-1])
    x = -1;
  else
  {
    if(str.length()>2)
      checkPalindromeRecursion(str.substr(1,str.length()-2));
  }

  if(x==-1)
  {
    return false;
  }
  else
    return true;
}

//-----------------------------------------------------------------------------
// runPalindromeCheck
//-----------------------------------------------------------------------------
void runPalindromeCheck()
{
  if(checkPalindromeRecursion("obamabo"))
    std::cout<<"Yes its true";
  else
    std::cout <<"No its not true";
}