#include <iostream>

void insertValueBack(int);
void insertValueFront(int);
void deleteValue(int);
void displayLinkedList();
void reverseSubList(int, int);
void reverseList();
void rightShift();
void rightShiftBy(int);
void pivotLinkedList(int);

struct node
{
  int data;
  node *next;
};

node *head, *tail;

//--------------------------------------------------------------------
// runClassicLinkedList
//--------------------------------------------------------------------
void runClassicLinkedList()
{

  head = NULL;
  tail = NULL;

  insertValueBack(2);
  insertValueBack(3);
  insertValueBack(11);
  insertValueBack(3);
  insertValueBack(4);
  insertValueBack(12);
  insertValueBack(7);
  insertValueBack(5);
  insertValueBack(53);
  insertValueBack(6);
  insertValueBack(13);

  displayLinkedList();

  std::cin.get();
  
}

//--------------------------------------------------------------------
// insertValueBack
//--------------------------------------------------------------------
void insertValueBack(int val)
{
node *temp = new node;

  temp->data = val;
  temp->next = NULL;

  if(head == NULL)
  {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else
  {
    node *local = head;
    while(local->next!=NULL)
      local = local->next;

    local->next = temp;
    temp->next = NULL;
  }
}


//--------------------------------------------------------------------
// insertValueFront
//--------------------------------------------------------------------
void insertValueFront(int val)
{
node *temp = new node;

  temp->data = val;
  temp->next = NULL;

  if(head == NULL)
  {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

//--------------------------------------------------------------------
// deleteValue
//--------------------------------------------------------------------
void deleteValue(int val)
{
node *temp = head;
node *back = head;
  
  while(temp!=NULL && temp->data!=val)
  {
    back = temp;
    temp=temp->next;
  }

  if(temp && temp->data == val)
  {
    if(temp == head)
    {
      head = temp->next;
    }
    else
    {
      if(temp->next!=NULL)
        back->next = temp->next;
      else
      {
        back->next = NULL;
        tail = back;
      }
    }
  }
}

//--------------------------------------------------------------------
// displayLinkedList
//--------------------------------------------------------------------
void displayLinkedList()
{
node *temp = head;

  while(temp!=NULL)
  {
    std::cout << temp->data << "\t";
    temp = temp->next;
  }
}

//--------------------------------------------------------------------
// reverseSubList
//--------------------------------------------------------------------
void reverseSubList(int n1, int n2)
{
  for(int k=0; k<(n2-n1+1)/2;k++)
  {
  int i=1;
  int j=1;
    
    auto *temp1 = head;
    auto *temp2 = head;
    
    while (i<n1+k)
    {
      temp1 = temp1-> next;
      i++;
    }
  
    while (j<n2-k)
    {
      temp2 = temp2-> next;
      j++;
    }

    if(temp1->data != temp2->data)
    {
      temp1->data = temp1->data + temp2->data;
      temp2->data = temp1->data - temp2->data;
      temp1->data = temp1->data - temp2->data;
    }
    
  }
}

//--------------------------------------------------------------------
// reverseList
//--------------------------------------------------------------------
void reverseList()
{
node *prev = NULL;
auto *curr = head;
node *next = NULL;

  //prev->next = NULL;

  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;  
    curr = next;
  }
  
  head = prev;

}

//--------------------------------------------------------------------
// rightShift
//--------------------------------------------------------------------
void rightShift()
{
node *temp = head;
node *prev = head;

  while (temp->next != NULL)
  {
    prev = temp;
    temp = temp->next;
  }
  
  temp->next = head;
  prev->next = NULL;
  head = temp;
}

//--------------------------------------------------------------------
// rightShiftBy
//--------------------------------------------------------------------
void rightShiftBy(int k)
{
node *prev = head;
node *temp = head;
node *tail = head;
node *finalHead;
int count = 0;
int NMinusK = 0;


  while (temp != NULL)
  {
    count++;
    prev = temp;
    temp=temp->next;
  }

  tail = prev;
  
  if(k > count)
    k = k%count;

  temp = head;
  prev = head;
  NMinusK = count-k;

  int i = 0;
  do
  {
    prev = temp;
    temp = temp->next;
    i++;
  }while(i<NMinusK);

  finalHead = prev->next;  
  prev->next = NULL;

  tail->next = head;
  head = finalHead;
}

//--------------------------------------------------------------------
// pivotLinkedList
//--------------------------------------------------------------------
void pivotLinkedList(int k)
{
node *curr = head;
node *nodeK = head;
node *prev = NULL;
node *temp = NULL;
  
  while (nodeK != NULL)
  {
    if(nodeK->data == k)
      break;

    nodeK = nodeK->next;
  }

  node *postNodeK = nodeK->next;

  while (curr != nodeK)
  {
    
    if(curr->data <= k)
    { 
      prev = curr;
      curr = curr->next;
    }
    else
    {
      prev->next = curr->next;
      curr->next = postNodeK->next;
      postNodeK->next = curr;
      postNodeK = postNodeK->next;
      curr = prev->next;
    }
  }

  node *preNodeK = prev;

  while (curr != NULL)
  {
    if (curr->data >= k)
    {
      prev = curr;
      curr = curr->next;
    }
    else
    {
      prev->next = curr->next;
      preNodeK->next = curr;
      curr->next = nodeK;
      preNodeK = curr;
      curr = prev->next;
    }
  }

}
