#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //---------------------------------brute tc=O(N2), SC=O(1)---------------------------------
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = INT_MIN, prod = 1;
    for (int i = 0; i < n; i++)
    {
      prod = 1;
      for (int j = i; j < n; j++)
      {
        prod = prod * nums[j];
        maxi = max(maxi, prod);
      }
    }
    return maxi;
  }

  //-------------------------------OPTIMAL TC=O(N), SC=O(1)-----------------------------
  int maxProductoptimal(vector<int> &nums)
  {
    int n = nums.size(), prefix = 1, suffix = 1, ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int left = i;
      int right = n - i - 1;
      prefix = prefix * nums[left];
      suffix = suffix * nums[right];
      int maxi = max(prefix, suffix);
      ans = max(ans, maxi);
      if (nums[left] == 0)
      {
        prefix = 1;
      }
      if (nums[right] == 0)
      {
        suffix = 1;
      }
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {-2, 0, -1};
  int product = sol.maxProductoptimal(nums);
  cout << "Maximum product is: " << endl
       << product;
  return 0;
}
