#include<iostream>
#include<string>
#include<vector>

using namespace std;

void stringReverse(std::string&);
bool judgeCircle(std::string);
int uniqueMorseRepresentations(vector<string>&);


//--------------------------------------------------------------------
// runString
//--------------------------------------------------------------------
void runString()
{
  std::string str = "UD";
  judgeCircle(str);
}

//--------------------------------------------------------------------
// stringReverse
//--------------------------------------------------------------------
void stringReverse(std::string &str)
{
  for (int i = 0; i<str.length() / 2; i++)
  {
    char temp = str[i];
    str[i] = str[str.length() - i - 1];
    str[str.length() - i - 1] = temp;
  }

  std::cout << str;
  std::cin.get();
}

//--------------------------------------------------------------------
// stringReverse
//--------------------------------------------------------------------
bool judgeCircle(std::string moves)
{
  int i = 0;
  int distance = 0 , height = 0;
  do
  {
    //moves[i] == 'L' ? --distance : (moves[i] == 'D' ? --height : (moves [i] == 'U' ? ++height : ++distance));
    if (moves[i] == 'L')
      distance--;
    if (moves[i] == 'R')
      distance++;
    if (moves[i] == 'D')
      height--;
    if (moves[i] == 'U')
      height++;

    i++;
  } while (moves[i] != '\0');

  if ((distance == 0) && (height == 0))
    return true;
  else
    return false;
}

//--------------------------------------------------------------------
//uniqueMorseRepresentations
//--------------------------------------------------------------------
int uniqueMorseRepresentations(vector<string>& words)
{
  vector<string> uniqueCodes;
  string morseCodes[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
    "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

  for (int i = 0; i<words.size(); i++)
  {
    string transformation = "";
    for (int j = 0; j<words[i].length(); j++)
    {
      transformation += morseCodes[words[i][j] - 97];
    }
    if (i == 0)
      uniqueCodes.push_back(transformation);
    else
    {
      int count = 0;
      for (int k = 0; k<uniqueCodes.size(); k++)
      {
        if (uniqueCodes[k] == transformation)
        {
          count++;
          break;
        }
      }
      if (count == 0)
        uniqueCodes.push_back(transformation);
    }
  }
  return uniqueCodes.size();
}