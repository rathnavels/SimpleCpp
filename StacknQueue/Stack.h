#pragma once


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void push(int data);
int pop();
int topElement();
int maxElement();
int evaluate(std::string exp);

//--------------------------------------------------------------------
// struct StackNode
//--------------------------------------------------------------------
class StackNode
{
public:
  int data;
  int maxx;
  StackNode *next;
};
StackNode *top;

//--------------------------------------------------------------------
// reverseList
//--------------------------------------------------------------------
void push(int data)
{
  StackNode *newNode = new StackNode();
  newNode->data = data;
  newNode->next = NULL;
  if(top == NULL)
  {
    top = newNode;
    top->maxx = newNode->data;
  }
  else 
  {
     newNode->next = top;
     int temp = maxElement();
     top = newNode;
     top->maxx = std::max(top->data, temp);
  }
}

//--------------------------------------------------------------------
// pop
//--------------------------------------------------------------------
int pop()
{
int topValue = -1;
  if(top)
  {
    topValue = top->data;
    StackNode *temp = top;

    temp = top->next;
    delete top;

    top = temp;
  }
  else
    cout << "\nStack Underflow\n";

  return topValue;
}

//--------------------------------------------------------------------
// topElement
//--------------------------------------------------------------------
int topElement()
{
  if(top)
    return top->data;
  else
  return -1;
}

//--------------------------------------------------------------------
// maxElement
//--------------------------------------------------------------------
int maxElement()
{
  if(top)
    return top->maxx;
  else
    return -1;
}

//--------------------------------------------------------------------
// printElements
//--------------------------------------------------------------------
void printElements()
{
StackNode *node = top;
  std::cout << "\n";
  while(node)
  { 
    std::cout << node->data << "\t";
    node = node->next;
  }
}

//--------------------------------------------------------------------
// reversePolishNotation
//--------------------------------------------------------------------
void reversePolishNotation()
{
  top = NULL;
  
  std::string exp = "3,4,*,1,+,-1,*,13,*,13,/";
  int count;
  
  std::size_t found = exp.find_first_of(",");
  int holder = 0;
  while(found!=std::string::npos)
  {      
     int x = std::stoi(exp.substr(holder,found));
     push(x);
     count = 0;
     holder = found+1;
     found = exp.find_first_of(",", found+1);

      if(exp[holder] == '+')
      {
        push(pop() + pop());
        count++;
      }
      else  if(exp[holder] == '-')
      {
        push(pop() - pop());
        count++;
      }
      else  if(exp[holder] == '*')
      {
        push(pop() * pop());
        count++;
      }
      else  if(exp[holder] == '/')
      {
        int top = pop();
        push(pop()/top);
        count++;
      }

      if(count > 0)
      {
        if(found==std::string::npos)
          break;
        else
          found = exp.find_first_of(",", found+1);

        if(holder<exp.length()-1)
          holder = holder + 2;
      }
      
  }

  printElements();
  
}

//--------------------------------------------------------------------
// matchParantheses
//--------------------------------------------------------------------
void matchParantheses()
{
  std::string str = "()()()";

  for(int i=0; i< str.length(); i++)
  {
    if(str[i] == '(')    
      push(40);
    else
    {
      if(top)
      {
        if(top->data == 40)
          pop();
      }
      else
      {
        std::cout << "No match guys. Sorry";
        return;
      }
    }
  }

  if(top==NULL)
    std::cout << "It matches";
  else
    std::cout << "No match guys. Sorry";
}

//--------------------------------------------------------------------
// runStack
//--------------------------------------------------------------------
void runStack()
{
  matchParantheses();
}


