#include<iostream>
#include<set>
#include<unordered_set>
#include<iterator>
#include<string>
#include<vector>

using namespace std;

void setTesting01()
{
  std::set<int> s;
  s.insert(-1);
  s.insert(-10);
  s.insert(3);

  for(int x : s)
    cout << x << std::endl;

  auto it = s.find(-1);
  if(it==s.end())
    cout<<"Not present\n";
  else
    cout <<"Its present\n";

  auto it2 = s.upper_bound(-1);
  cout << *it2;
}


//--------------------------------------------------------------------
// setTesting_FindDuplicate
//--------------------------------------------------------------------
void setTesting_FindDuplicate()
{
  vector<int> arr = {2,5,7,3,1,6,3,9,8,5,2};
  //vector<int>::iterator i = arr.begin();

  unordered_set<int> main;

  for(int i:arr)
  {
    if(main.find(i) == main.end())
      main.insert(i);
    else
    {
      std::cout << "The first duplicate is " << i;
      return;
    }
  }
}

void setProblem()
{
  set<pair<int, int>> S;

  S.insert({30,400});
  S.insert({10,20});
  S.insert({2,3});
  S.insert({401,500});

  int point = 35;

  auto it = S.upper_bound({point, INT_MAX});
  if(it == S.begin())
  { 
    std::cout << "Not available" ;
    return;
  }

  it--;

  pair<int, int>current = *it;
  if(current.first <= point && point <= current.second)
  {
    cout << "Yes" << ". Its between " << current.first << " and " << current.second  ;
  }
  else
    cout << "No";
  
}

