#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //----------------------------------------Brute-------------------------------------------
  //----------------------------------TC=O(N^3)->SC=O(1)----------------------------
  // apply four loops and then iterate

  //---------------------------------Better-------------------------------------------
  //---------------------------TC=O(N^2(LOGN+LOGM)), SC=O(N)--------------------------

  vector<vector<int>> fourSumbetter(vector<int> &nums, int target)
  {
    int n = nums.size();
    set<vector<int>> temp;
    for (int i = 0; i < n - 2; i++)
    { // O(N)
      set<int> hashset;
      for (int j = i + 1; j < n - 1; j++)
      { // O(N)
        for (int k = j + 1; k < n; k++)
        { // O(N)
          int fourth = -(nums[i] + nums[j] + nums[k]);
          if (hashset.find(fourth) != hashset.end())
          {                                                          // O(LOGN)->FOR SEARCHING
            vector<int> tempp = {nums[i], nums[j], nums[k], fourth}; //->O(1)
            sort(tempp.begin(), tempp.end());                        // O(NLOGN=3LOG3=1)
            temp.insert(tempp);                                      // O(LOGM)
          }
          hashset.insert(nums[k]); // O(LOGN)
        }
      }
    }
    vector<vector<int>> ans(temp.begin(), temp.end()); // O(N)
    return ans;
  }

  //--------------------------------------------------------------------------
  vector<vector<int>> fourSumoptimal(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < n - 2; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int left = j + 1;
        int right = n - 1;
        while (left < right)
        {
          long long sum;
          sum = (long long)nums[i] + (long long)nums[left] + (long long)nums[right] + (long long)nums[j];
          if (sum == target)
          {
            ans.push_back({nums[i], nums[left], nums[right], nums[j]});
            left++, right--;
            while (left < right && nums[left] == nums[left - 1])
              left++;
            while (left < right && nums[right] == nums[right + 1])
              right--;
          }
          else if (sum > target)
          {
            right--;
          }
          else
          {
            left++;
          }
        }
      }
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {-1, -2, 0, 0, 1, 2, -1, 2};
  int target = 0;
  vector<vector<int>> res1 = sol.fourSumbetter(nums, target);
  vector<vector<int>> res2 = sol.fourSumoptimal(nums, target);
  for (auto &x : res1)
  {
    cout << "[" << x[0] << x[1] << x[2] << x[3] << "]";
  }
}
