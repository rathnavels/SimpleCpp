#include<iostream>
#include<set>
#include<iterator>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


void commonChars()
{
  std::vector<std::string> A;
  A.push_back("cool");
  A.push_back("lock");
  A.push_back("cook");

  std::map<char, int>    count;
  std::map<char, int>    localCount;
  std::vector<string> ret;

  for (int i = 0; i<A.size(); i++)
  {
    for (int j = 0; j<A[i].size(); j++)
    {
      if (i == 0)
      {
        char c = A[i][j];
        count[c]++;
      }
      else
      {
        char c = A[i][j];
        localCount[c]++;
      }
    }
    if (i>0)
    {
      for (auto itr = count.begin(); itr != count.end(); itr++)
      {
        auto ct_itr = localCount.find(itr->first);

        if (ct_itr != localCount.end())
        {
          itr->second = std::min(ct_itr->second, itr->second);
        }
        else
        {
          itr->second = 0;
        }
      }
      localCount.clear();
    }
  }

  for (auto itr : count)
  {

    for (int i = 0; i<itr.second; i++)
      ret.push_back(std::string(1, itr.first));
  }

  std::cin.get();
}

