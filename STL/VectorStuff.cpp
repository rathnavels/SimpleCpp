#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool f(int x, int y)
{
  return x>y;
}

void vectorTesting()
{
std::vector<int>  A = {11,2,3,14};

  std::sort(A.begin(), A.end());
  bool present = std::binary_search(A.begin(),A.end(),2);

  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  A.push_back(100);
  A.push_back(131);

  auto it1 = std::lower_bound(A.begin(), A.end(), 100);
  auto it2 = std::upper_bound(A.begin(), A.end(), 100);

  cout << *it1 << " " << *it2 << endl;
  cout << it2 - it1 << endl;

  sort(A.begin(),A.end(),f);

  for(int x:A)
  {
    std::cout << x << ' ';
  }

  std::cin.get();
}