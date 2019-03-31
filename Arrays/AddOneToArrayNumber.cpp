#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//[1,2,3] -> [1,2,4]
//[9,9,9] -> [1,0,0,0]


void printarray(vector<int> &arr)
{
  for(int i=0; i<arr.size(); i++)
    std::cout << arr[i] << "\t";

  cout << endl;
}

vector<int> letsDoThis(vector<int> &arr)
{
  int carryOver = 1;
  int sz = arr.size();
  vector<int> returnV;
  
  for (int i = arr.size() - 1; i >= 0 ; i--)
  {
    arr[i] = arr[i]+carryOver;
    carryOver = (arr[i]==10) ? 1 : 0;
    
    returnV.insert(returnV.begin(),arr[i]%10);
  }

  if(carryOver)
    returnV.insert(returnV.begin(), 1);

  return returnV;
}


void runAddOneToArrayNumber()
{
  vector<int> arrary = {1,4,2,3};

  cout << "The array before addition \n";
  printarray(arrary);

  vector<int> finalArr = letsDoThis(arrary);

  cout << "The array after addition \n";
  printarray(finalArr);
}
