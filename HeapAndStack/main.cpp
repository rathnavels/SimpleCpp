// This is to study heap and study

#include <iostream>
struct Vector3
{

};

int main()
{
	int value = 5;
	int array[5] = {1,2,3,4,5};

	int *hvalue = new int;
	*hvalue = 5; 
	int *harray = new int[5];
	for (int i = 0; i < 5; i++)
		harray[i] = i + 1;

	std::cin.get();
}