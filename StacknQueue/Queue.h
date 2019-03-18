#pragma once

#include <iostream>

using namespace std;

void enqueue(int data);
void dequeue();
void frontElement();
void rearElement();
void printElementsQueue();

//--------------------------------------------------------------------
// QueueNode
//--------------------------------------------------------------------
struct QueueNode
{
  int data;
  QueueNode *next;  
};

QueueNode *front, *rear;


//--------------------------------------------------------------------
// enqueue
//--------------------------------------------------------------------
void enqueue(int data)
{
  QueueNode *temp = new QueueNode();
  temp->data = data;
  temp->next = NULL;
  if(front == NULL)
  {
    front = temp;
    rear = front;
  }
  else
  {
    temp->next = rear;
    rear = temp;
  }
}

//--------------------------------------------------------------------
// dequeue
//--------------------------------------------------------------------
void dequeue()
{
  QueueNode *temp = NULL;
  if(front == NULL)
  {
    std::cout << "\nQueue is empty\n";
  }
  else if(rear->next == NULL)
  {
    rear = NULL;
    front = NULL;
  }
  else
  {
    temp = rear;
    while(temp->next!=front)  
    {
      temp = temp->next;
    }
    front = temp;
    front->next = NULL;
  }
}

//--------------------------------------------------------------------
// frontElement
//--------------------------------------------------------------------
void frontElement()
{
  if(front)
    std::cout << "\nThe front Element is " << front->data << "\n";
  else
    std::cout << "\nQueue is empty\n";
}

//--------------------------------------------------------------------
// rearElement
//--------------------------------------------------------------------
void rearElement()
{
  if(rear)
    std::cout << "\nThe rear Element is " << rear->data << "\n";
  else
    std::cout << "\nQueue is empty\n";
}

//--------------------------------------------------------------------
// printElements
//--------------------------------------------------------------------
void printElementsQueue()
{
  std::cout << "\nThe elements in the queue are \n";
  if(rear)
  {
    QueueNode *temp = rear;
    while(temp)
    {
      std::cout << temp->data << "\t";
      if(rear!=front)
        temp = temp->next;
      else
        break;
    }
  }
  else
  {
    std::cout << "\nQueue is empty\n";
  }
}

//--------------------------------------------------------------------
// runQueue
//--------------------------------------------------------------------
void runQueue()
{
  front = NULL;
  rear = NULL;
  enqueue(56);
  enqueue(26);
  enqueue(29);
  enqueue(12);
  dequeue();
  enqueue(43);
  enqueue(65);
  dequeue();
  enqueue(35);
  enqueue(21);
  dequeue();
  enqueue(29);
  dequeue();
  enqueue(93);
  dequeue();

  printElementsQueue();
  frontElement();
  rearElement();

  dequeue();
  dequeue();
  dequeue();

  printElementsQueue();
  frontElement();
  rearElement();

  dequeue();
  dequeue();
  dequeue();

  printElementsQueue();
  frontElement();
  rearElement();
  
}

