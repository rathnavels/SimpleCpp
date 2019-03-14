#include<iostream>
#include<vector>

using namespace std;

vector<string> commonChars(vector<string>& A) ;

void printIt()
{
  std::vector<string> inputs = {"hello","hi","vanakkam"};
  std::vector<string> results = commonChars(inputs);

  for(int i=0; i<results.size(); i++)
  {
      std::cout << results[i].c_str();
  }
}

vector<string> commonChars(vector<string>& A) 
{
    vector<string> output;
        
    output.push_back("a");
    output.push_back("e");
    output.push_back("l");
        
      output.push_back(string(1, A[0][0]));
        
  return output;
}