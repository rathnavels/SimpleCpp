#include <list>
#include <vector>
#include <iostream>

using namespace std;

void runSTLList()
{
	std::list<int> L;

	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	std::cout << *(++L.begin());
}