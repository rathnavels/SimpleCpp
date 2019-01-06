#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int smallestRangeI(vector<int>& A, int K);

void runLC908()
{

  vector<int> A = {0,10};
  int K = 2;
  int f = smallestRangeI(A,K);
  std::cin.get();

}

int smallestRangeI(vector<int>& A, int K)
{
  std::sort(A.begin(), A.end());
  int numElements = A.size();
  int originalGap = A[numElements-1] - A[0];
  int rangeK = (K>0) ? (K * 2 + 1) : 0;
  int retValue = -1;

  if (rangeK > originalGap)
    retValue = 0;
  else
    retValue = (A[numElements - 1] - K) - (A[0] + K);

  return retValue;
}