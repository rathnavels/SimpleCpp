#pragma once


#include <iostream>

using namespace std;

void push(int &data);
void pop();
int topElement();

//--------------------------------------------------------------------
// struct StackNode
//--------------------------------------------------------------------
struct StackNode
{
  int data;
  StackNode *next;
};
struct StackNode *top;

//--------------------------------------------------------------------
// reverseList
//--------------------------------------------------------------------
void push(int data)
{
  StackNode *newNode = new StackNode();
  newNode->data = data;
  newNode->next = NULL;
  if(top == NULL)
    top = newNode;
  else 
  {
     newNode->next = top;
     top = newNode;
  }
}

//--------------------------------------------------------------------
// pop
//--------------------------------------------------------------------
void pop()
{
  if(top)
  {
    StackNode *temp = top;

    temp = top->next;
    delete top;

    top = temp;
  }
  else
    cout << "\nStack Underflow\n";
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
// printElements
//--------------------------------------------------------------------
void printElements()
{
StackNode *node = top;
  while(node)
  { 
    std::cout << node->data << "\t";
    node = node->next;
  }
}

//--------------------------------------------------------------------
// runStack
//--------------------------------------------------------------------
void runStack()
{
  top = NULL;

  push(5);
  push(10);
  push(15);
  push(25);
  pop();
  push(45);
  push(65);
 if(topElement()!=-1)
    cout << "\nThe top element is " << topElement() << "\n";
  printElements();
  push(33);
  pop();
  pop();
  pop();
 if(topElement()!=-1)
    cout << "\nThe top element is " << topElement() << "\n";
  printElements();
  pop();
  pop();
  pop();
  pop();
  push(27);
  push(37);
 if(topElement()!=-1)
    cout << "\nThe top element is " << topElement() << "\n";
  printElements();
  push(21);
  push(26);
  pop();
  pop();
 if(topElement()!=-1)
    cout << "\nThe top element is " << topElement() << "\n";
  printElements();
  pop();
  pop();
  pop();
  pop();

  if(topElement()!=-1)
    cout << "\nThe top element is " << topElement() << "\n";
  printElements();

}

