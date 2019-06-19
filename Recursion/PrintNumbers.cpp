#include <iostream>
using namespace std;

void printNumbersUtil(int x, int N);

void printNumbers(int N)
{
	printNumbersUtil(1, N);
}

void printNumbersUtil(int x, int N)
{
	if (x == N + 1)
		return;

	std::cout << x << " ";
	printNumbersUtil(++x, N);
}