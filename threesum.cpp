#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //----------------------------------------Brute-------------------------------------------
  //----------------------------------TC=O(N^3)->SC=O(1)----------------------------
  // apply three loops and then iterate

  //---------------------------------Better-------------------------------------------
  //---------------------------TC=O(N^2(LOGN+LOGM)), SC=O(N)--------------------------

  vector<vector<int>> threeSumbetter(vector<int> &nums)
  {
    int n = nums.size();
    set<vector<int>> temp;
    for (int i = 0; i < n; i++)
    { // O(N)
      set<int> hashset;
      for (int j = i + 1; j < n; j++)
      { // O(N)
        int third = -(nums[i] + nums[j]);
        if (hashset.find(third) != hashset.end())
        {                                                // O(LOGN)->FOR SEARCHING
          vector<int> tempp = {nums[i], nums[j], third}; //->O(1)
          sort(tempp.begin(), tempp.end());              // O(NLOGN=3LOG3=1)
          temp.insert(tempp);                            // O(LOGM)
        }
        hashset.insert(nums[j]); // O(LOGN)
      }
    }
    vector<vector<int>> ans(temp.begin(), temp.end()); // O(N)
    return ans;
  }

  //--------------------------------------------------------------------------

  vector<vector<int>> threeSumoptimal(vector<int> &nums)
  {
    int n = nums.size();
    set<pair<int, pair<int, int>>> hashset;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
      int left = i + 1;
      int right = n - 1;
      while (left < right)
      {
        int sum = nums[left] + nums[i] + nums[right];
        if (sum == 0)
        {
          hashset.insert({nums[i], {nums[left], nums[right]}});
          left++;
          right--;
        }
        else if (sum > 0)
        {
          right--;
        }
        else
        {
          left++;
        }
      }
    }
    vector<vector<int>> ans;
    for (auto &x : hashset)
    {
      int first = x.first;
      int second = x.second.first;
      int third = x.second.second;
      ans.push_back({first, second, third});
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res1 = sol.threeSumbetter(nums);
  vector<vector<int>> res2 = sol.threeSumoptimal(nums);
  for (auto &x : res1)
  {
    cout << "[" << x[0] << x[1] << x[2] << "]";
  }
}
