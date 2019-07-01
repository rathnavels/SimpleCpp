using namespace std;
#include <iostream>


class BaseClass
{
	int x;
	float *y;
	virtual void func1()
	{

	}
};

class DerivedClass : public BaseClass
{
	int y;
	void func1()
	{

	}
	void func2()
	{

	}
};

void runObjectSize()
{
	std::cout << sizeof(BaseClass) << endl;
	std::cout << sizeof(DerivedClass);
}