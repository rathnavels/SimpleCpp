#include<iostream>

struct node
{
  int data;
  struct node *leftChild;
  struct node *rightChild;
};

node *root = NULL;

//-----------------------------------------------------------
// search
//-----------------------------------------------------------
node* search(int data)
{
  node* current = root;

  if(root==NULL)
    return NULL;

  if(root->data == data)
    return root;
  
  while(1)
  {
    if(current->data > data)  
      current = current->leftChild;
    else
      current = current->rightChild;

    if(current==NULL)   
      return NULL;
    else if (current->data == data)
      return current;
  }
}

//-----------------------------------------------------------
// insert
//-----------------------------------------------------------
void insert(int data)
{
  node *current = NULL;
  node *parent  = NULL;
  
  node *temp = new node();
  temp->data = data;
  temp->leftChild = NULL;
  temp->rightChild = NULL;

  if(root == NULL)
  {
    root = temp;
    return;
  }

  current = root;
  parent = NULL;
  while(current!=NULL)
  {
    parent = current;

    if(current->data > data)
    {
      current = current->leftChild;

      if(current==NULL)
        parent->leftChild = temp;
    }
    else
    { 
      current = current->rightChild;
      
      if(current==NULL)
        parent->rightChild = temp;
    }
  }
}


//-----------------------------------------------------------
// inorder traversal
//-----------------------------------------------------------
void inorder(node *root)
{
  if(root!=NULL)
  {
    inorder(root->leftChild);
    std::cout << root->data << "\t";
    inorder(root->rightChild);
  }
}

//-----------------------------------------------------------
// preorder traversal
//-----------------------------------------------------------
void preorder(node *root)
{
  if(root!=NULL)
  {
    std::cout << root->data << "\t";
    preorder(root->leftChild);
    preorder(root->rightChild);
  }
}

//-----------------------------------------------------------
// postorder traversal
//-----------------------------------------------------------
void postorder(node *root)
{
  if(root!=NULL)
  {
    postorder(root->leftChild);
    postorder(root->rightChild);
    std::cout << root->data << "\t";
  }
}

//-----------------------------------------------------------
// main
//-----------------------------------------------------------
void main()
{
  insert(50);
  insert(40);
  insert(60);
  insert(45);
  insert(70);
  insert(30);
  insert(80);
  insert(20);

  inorder(root); 
  std::cout << std::endl;
  preorder(root);
  std::cout << std::endl;
  postorder(root);
  std::cout << std::endl;

  if(search(50))
    std::cout << "It was found boys\n";
  else
    std::cout << "It was not found boys\n";

  std::cin.get();
}

