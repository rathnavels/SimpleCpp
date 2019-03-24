#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void longestCommonSubsequence()
{
  string X ="AquaVitae";
  string Y="AuaVae";
  size_t m = X.length()+1;
  size_t n = Y.length()+1;
    int** L = new int*[m];

    for(int j = 0; j < m; ++j)
        L[j] = new int[n];
  
   for (int i=0; i<m; i++) 
   { 
     for (int j=0; j<n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 

  std::cout << "LCS value is" << L[m-1][n-1];
}