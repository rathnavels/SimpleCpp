#include<iostream>
#include<set>
#include<iterator>
#include<string>
#include<vector>
#include<map>

using namespace std;

void mapTesting()
{
  map<int, int> A;
  A[1] = 100;
  A[2] -1;
  A[3] = 200;
  A[232] = 150;

  map<char, int> cnt;
  string x = "rathinavela";

  for(char c : x)
  {
    cnt[c]++;
  }

  cout << cnt['a'];
}