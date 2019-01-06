#include<vector>
#include<iostream>
using namespace std;

bool checkPossibility(vector<int>& nums);

void runArray()
{
vector<int> A = {1,2,3,4};

std::cout << checkPossibility(A);
std::cin.get();

}

bool checkPossibility(vector<int>& nums)
{
  int conflict = 0;
  int i = 1;
  int countA=0, countB=0;
  vector<int> A, B;
  int conflictPosition1, conflictPosition2;
  while (i<nums.size())
  {
    if (nums[i] < nums[i - 1])
    {
      conflict++;
      if (conflict == 1)
      {
        conflictPosition1 = i - 1;
        conflictPosition2 = i;
      }
    }
    i++;
  }


  if (conflict > 1)
    return false;
  else if (conflict == 0)
    return true;
  else
  {
    for (int i = 0; i<nums.size(); i++)
    {
      if (i<conflictPosition1 || i>conflictPosition2)
      {
        A.push_back(nums[i]);
        B.push_back(nums[i]);
      }
      else
      {
        A.push_back(nums[conflictPosition1]);
        B.push_back(nums[conflictPosition2]);
      }
    }

    for (int i = 1; i < A.size(); i++)
    {
      if (A[i - 1] <= A[i])
      {
      }
      else
        countA++;

      if (B[i - 1] <= B[i])
      {
      }
      else
        countB++;
    }
    if (countA == 0 || countB == 0)
      return true;
    else
      return false;
  }


}