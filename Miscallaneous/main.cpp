/* Enter your macros here */
#define toStr(a)        string("Result =")
#define io(v)           std::cin >> v
#define FUNCTION(name, operator) void name(int &current, int &newValue){ if(!(current operator newValue)) current = newValue;}
#define INF   INT_MAX
#define foreach(v, i)  for(int i=0; i<v.size(); i++)


#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){

	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) 
  {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
  int ans = 0;


  foreach(v, i)
  {
    	minimum(mn, v[i]);
		  maximum(mx, v[i]);
  }
  ans = mx-mn;

	cout << toStr(Result =) <<' '<< ans;
	
return 0;
}