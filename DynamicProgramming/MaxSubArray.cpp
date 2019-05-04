#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> arr;

void runMaxSubArray()
{

	int currentMax = 0, overallMax = 0;
	arr = { -2,3,-2,-1,3,-2,5 };
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

	std::cout << overallMax;
}