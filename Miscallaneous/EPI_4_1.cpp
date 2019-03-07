#include <iostream>
#include <limits>
#include <limits.h>

short CountBits(int);
void randomOperation(void);

void countBitsEPI_4_1()
{
  randomOperation();

  std::cin.get();
}


short CountBits(int x)
{
  short int numBits=0;
  while (x)
  {
    numBits += x & 1;
    x >>= 1;
  }

  return numBits;
}

void randomOperation(void)
{
  std::cout << std::abs(-3.2) << std::endl;
  std::cout << std::fabs(-3.14) << std::endl;
  std::cout << std::ceil(2.17) << std::endl;
  std::cout << std::floor(3.14) << std::endl;
  
}