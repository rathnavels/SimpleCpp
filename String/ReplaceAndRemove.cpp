#include<string>
#include<iostream>
#include<sstream>
using namespace std;

// Replace a with double d's
// Remove b's

void runReplaceAndRemove()
{
  int size = 4;
  int writeId = 0;
  int countA =0;
  char c[] = {'a','c','a','a','a','c','b','3','q','b','3','q' };
  // {d,d,c,d,d,d,c,b,3,1,b,3,q}
  for (int i = 0; i < size; i++)
  {
    if(c[i]!='b')
      c[writeId++] = c[i];
    if(c[i]=='a')
      countA++;
  }
 // {a,c,d,a,   c,b....}
  int newSize = writeId + countA - 1;
  int ptr = writeId - 1;
  for (int i = ptr; i >= 0; i--)
  {
    if(c[i] == 'a')
    {
      c[newSize] = 'd';
      c[newSize -1] = 'd';
      newSize-=2;
    }
    else
    { 
      c[newSize] = c[i];
      newSize -= 1;
    }
    
  }
  
  std::cin.get();
}