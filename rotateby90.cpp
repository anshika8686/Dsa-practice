#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < n; i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};
int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  sol.rotate(matrix);
  cout << "Matrix after 90 degree rotation";
  for (auto row : matrix)
  {
    cout << endl;
    for (auto it : row)
    {
      cout << it;
    }
  }
}