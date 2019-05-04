#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> arr;


void runMaxSubArray()
{

  int start = -1, end = -1;

	int currentMax = 0, overallMax = 0;
	arr = { 21, -15, 22, 31, -12, 44, 7, 5,24, -1, 8, -21, -15, 32};
	for (int i = 0; i < arr.size()-1; i++)
	{
		int sum = 0;
		currentMax = 0;
		for (int j = i; j < arr.size(); j++)
		{
			sum += arr[j];
			currentMax = max(currentMax, sum);
		}
		overallMax = max(overallMax, currentMax);
	}


  for (int i = 0; i < arr.size()-1; i++)
	{
    int sum = 0;
		currentMax = 0;
		for (int j = i; j < arr.size(); j++)
		{
			sum += arr[j];
			currentMax = max(currentMax, sum);
      if(overallMax == currentMax)
        {
          start = i;
          end = j;
          break;
        }
		}
	}


	std::cout << overallMax << " " << start << " " << end;
}