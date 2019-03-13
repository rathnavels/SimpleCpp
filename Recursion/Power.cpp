#include<iostream>



//-----------------------------------------------------------------------------
// computePower
//-----------------------------------------------------------------------------
int computePower(int x, int n)
{
  if(n==0)
    return 1;

  if(n%2==0)
  {
    int ans = computePower(x,n/2) ;
    return ans * ans; 
  }
  else
    return x * computePower(x,n-1);
}

//-----------------------------------------------------------------------------
// Power
//-----------------------------------------------------------------------------
void findPowerRecursion()
{

  std::cout << computePower(6,4);
  
}