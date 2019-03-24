#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

int unOrderedMapTesting()
{
  int n;
  cin >> n;

  long long S = 0;

  vector<int> A(n+5,0);

  for(int i=0; i<n; i++) cin >> A[i], S+= A[i];

  if(S&1)
  {
    cout << "No";
    return 0;
  }

  map<long long, int> first, second;

  first[A[0]] = 1;

  for(int i=1; i<n; i++)
    second[A[i]]++;

  long long sdash = 0;

  for(int i=0; i<n; i++)
  {
    sdash += A[i];
    if(sdash == S/2)
    {
      cout << "Yes\n";
      return 0;
    }
    if(sdash < S/2)
    {
      long long x = S/2 - sdash;
      if(second[x] > 0)
        {
          cout << "Yes\n";
          return 0;
        }
    }
    else
    {
      long long y = sdash - S/2;
      if(first[y] > 0)
      {
        cout << "Yes\n";
        return 0;
      }
    }
    first[A[i+1]]++;
    second[A[i+1]]--;
  }
  
}