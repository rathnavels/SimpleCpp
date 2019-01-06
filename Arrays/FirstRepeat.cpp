#include <iostream>
#include <vector>

using namespace std;

bool firstRepeatNumber(vector<int>& arr, int &rN);

//--------------------------------------------------------------------------
// runFirstRepeat
//--------------------------------------------------------------------------
void runFirstRepeat()
{
  vector<int> arr = {5,4,3,6,1,2};
  int rN;
  firstRepeatNumber(arr, rN) ? std::cout << rN : std::cout << "Value Not found";
  std::cin.get();
}

//--------------------------------------------------------------------------
// firstRepeatNumber
//--------------------------------------------------------------------------
bool firstRepeatNumber(vector<int>& arr, int& repeatNumber)
{
  vector<int> local;
  bool valFound = false;
  for (int i = 0; i < arr.size(); i++)
  {
    if(i==0)
      local.push_back(arr[i]);
    else
    {
      for (int j = 0; j < local.size(); j++)
      {
        if (local[j] == arr[i])
        {
          repeatNumber = arr[i];
          valFound = true;
          break;
        }
      }
      local.push_back(arr[i]);
    }
  if(valFound)
    break;
  }
return valFound;
}