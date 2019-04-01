#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
void runReverseVowels()
{
  string original = "hello world";

  auto word = string("");

  for (int i = 0; i <= original.size()-1; i++)
  {
    char c = original[i];
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u' )
      word += c;
  }

  reverse(word.begin(),word.end());
  int pointer = 0;
  for (int i = 0; i <= original.size() - 1; i++)
  {
    char c = original[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      original[i] = word[pointer++];
  }

  cout << original;
}