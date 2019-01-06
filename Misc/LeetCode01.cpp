#include<iostream>
#include<vector>
#include<cstdlib>

int hammingDistance(int x, int y);

//--------------------------------------------------------------------------
// hammingDistance
//--------------------------------------------------------------------------
void runHammingDistance()
{
  std::cout << hammingDistance(41,47);
  std::cin.get();
}

//--------------------------------------------------------------------------
// hammingDistance
//--------------------------------------------------------------------------
int hammingDistance(int x, int y)
{
  std::vector<int> X;
  std::vector<int> Y;
  int hammingDist = 0;

  while (x)
  {
    X.push_back(x % 2);
    x = x / 2;
  }

  while (y)
  {
    Y.push_back(y % 2);
    y = y / 2;
  }

  int xSize = X.size();
  int ySize = Y.size();

  int difference = abs(xSize - ySize);
  int maxValue = X.size() > Y.size() ? X.size() : Y.size();
  int minValue = X.size() < Y.size() ? X.size() : Y.size();

  for (int i = minValue; i<maxValue; i++)
  {
    if (X.size() == maxValue)
      Y.push_back(0);
    else
      X.push_back(0);
  }

  for (int i = 0; i<maxValue; i++)
  {
    if (X[i] != Y[i])
      hammingDist++;
  }

  return hammingDist;

}