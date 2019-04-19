#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void runHexa()
{
  int number = 21;
  int hexa;
  std::stringstream stream;

  
  stream << number;
  stream >> std::hex >> hexa;
  
  cout << hexa;
  
}