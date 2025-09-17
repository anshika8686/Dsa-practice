#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //-----------------------------BRUTE TC=O(N^2) SC=O(1)--------------------------------------
  // atmost two elements is the majrity element
  vector<int> majorityElementbrute(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
      count = 1;
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] == nums[j])
        {
          count++;
        }
      }
      if (count > n / 3 && find(ans.begin(), ans.end(), nums[i]) == ans.end())
      { // remove duplicates too
        ans.push_back(nums[i]);
      }
    }
    return ans;
  }

  //---------------------------------BETTER-TC=O(N) SC=O(N)-------------------------------------)
  vector<int> majorityElementbetter(vector<int> &nums)
  {
    int n = nums.size();
    map<int, int> hashmap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      hashmap[nums[i]]++;
    }
    for (auto it : hashmap)
    {
      int element = it.first;
      int freq = it.second;
      if (freq > n / 3)
      {
        ans.push_back(element);
      }
    }
    return ans;
  }

  //---------------------------OPTIMAL TC=O(2N) SC=O(1)--------------------------------------
  vector<int> majorityElementoptimal(vector<int> &nums)
  {
    int n = nums.size();
    int cnd1 = 0, cnd2 = 0, cnt1 = 0, cnt2 = 0;
    for (int num : nums)
    { // O(N)
      if (num == cnd1)
      {
        cnt1++;
      }
      else if (num == cnd2)
      {
        cnt2++;
      }
      else if (cnt1 == 0)
      {
        cnd1 = num;
      }
      else if (cnt2 == 0)
      {
        cnd2 = num;
      }
      else
      {
        cnt1--, cnt2--;
      }
    }
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
    { // O(N)
      if (cnd1 == nums[i])
      { // first we found that two numbers and then we counted the numbers of times they occured.
        cnt1++;
      }
      else if (cnd2 == nums[i])
      {
        cnt2++;
      }
    }
    vector<int> ans;
    if (cnt1 > n / 3)
    {
      ans.push_back(cnd1);
    }
    if (cnt2 > n / 3)
    {
      ans.push_back(cnd2);
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<int> arr = {2, 1, 2, 1, 1, 2, 2, 2};

  auto brute = sol.majorityElementbrute(arr);
  auto better = sol.majorityElementbetter(arr);
  auto optimal = sol.majorityElementoptimal(arr);

  cout << "Brute: ";
  for (int x : brute)
    cout << x << " ";
  cout << endl;

  cout << "Better: ";
  for (int x : better)
    cout << x << " ";
  cout << endl;

  cout << "Optimised: ";
  for (int x : optimal)
    cout << x << " ";
  cout << endl;

  return 0;
}
