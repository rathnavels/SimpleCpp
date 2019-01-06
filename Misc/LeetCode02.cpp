#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

//--------------------------------------------------------------------------
// fmax
//--------------------------------------------------------------------------
int fmax(vector<int> &gridLine)
{
  int maxi = 0;
  for (int i = 0; i<gridLine.size(); i++)
    maxi = maxi >= gridLine[i] ? maxi : gridLine[i];

  return maxi;
}


//--------------------------------------------------------------------------
// findMaxTB
//--------------------------------------------------------------------------
void findMaxTB(vector<vector<int>>& grid, vector<int> &TB)
{
  
  for (int j = 0; j<grid.size(); j++)
  {
    vector<int> column;
    for (int i = 0; i<grid[j].size(); i++)
    {   
      column.push_back(grid[i][j]);
    }

    TB.push_back(fmax(column));
  }
}

//--------------------------------------------------------------------------
// findMaxLR
//--------------------------------------------------------------------------
void findMaxLR(vector<vector<int>>& grid, vector<int> &LR)
{
  for (int i = 0; i<grid.size(); i++)
  {
    LR.push_back(fmax(grid[i]));
  }
}


//--------------------------------------------------------------------------
// maxIncreaseKeepingSkyline
//--------------------------------------------------------------------------
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
{
  vector<int> TB, LR;
  vector<vector<int>> gridNew(50);
  vector<vector<int>> sub(50);
  int maxIncrease = 0;
  findMaxTB(grid, TB);
  findMaxLR(grid, LR);

  for (int i = 0; i<grid.size(); i++)
  {
    for (int j = 0; j<grid[i].size(); j++)
    {
      gridNew[i].push_back(min(LR[i], TB[j]));
      sub[i].push_back(gridNew[i][j] - grid[i][j]);
      maxIncrease += sub[i][j];
    }
  }
  std::cout << "Here" << "\t";
  return maxIncrease;
}

//--------------------------------------------------------------------------
// runSkyline
//--------------------------------------------------------------------------
void runSkyline()
{
  vector<vector<int>> grid;
  grid.push_back({ 3, 0, 8, 4 });
  grid.push_back({ 2, 4, 5, 7 });
  grid.push_back({ 9, 2, 6, 3 });
  grid.push_back({ 0, 3, 1, 0 });
  std::cout << maxIncreaseKeepingSkyline(grid);
  std::cin.get();
}