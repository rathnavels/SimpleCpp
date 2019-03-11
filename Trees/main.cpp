#include<iostream>
#include<algorithm>

struct BalancedStatusWithHeight
{
  bool balanced;
  int height;
};

struct node
{
  int data;
  struct node *leftChild;
  struct node *rightChild;
};

node *root = NULL;

BalancedStatusWithHeight CheckBalanced(node *tree);

bool IsBalanced(node *root)
{
  return CheckBalanced(root).balanced;
}

BalancedStatusWithHeight CheckBalanced(node *tree)
{
  if(tree == NULL)
  return {true, -1};

  auto left_result = CheckBalanced(tree->leftChild);
  if(!left_result.balanced)
  {
    return {false,0};
  }

  auto right_result = CheckBalanced(tree->rightChild);
  if(!right_result.balanced)
  {
    return {false, 0};
  }

  bool is_balanced = abs(left_result.height - right_result.height) <= 1;
  int height = std::max(left_result.height , right_result.height) +1;
  return {is_balanced, height};
}



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
  insert(10);
  insert(20);

  inorder(root); 
  std::cout << std::endl;
  preorder(root);
  std::cout << std::endl;
  postorder(root);
  std::cout << std::endl;

  if(IsBalanced(root))
    std::cout << "It is balanced boys\n";
  else
    std::cout << "It is not balanced boys\n";

  std::cin.get();
}

