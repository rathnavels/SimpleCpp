#include<iostream>
#include<set>
#include<iterator>
#include<string>
#include<vector>
#include<map>

using namespace std;

void mapTesting()
{
  map<char, int> cnt;
  string x = "rathinavela";

  for(char c : x)
  {
    cnt[c]++;
  }

  cout << cnt['a'];
}

