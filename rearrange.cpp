#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  //----------------------------------------Brute-------------------------------------------
  //----------------------------------TC=O(N)->SC=O(N)------------------------------------

  vector<int> rearrangeArraybrute(vector<int> &nums)
  {
    int n = nums.size(), k = 0, j = 0;
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    { // TC=O(N)
      if (nums[i] > 0)
      {
        pos.push_back(nums[i]);
      }
      else
      {
        neg.push_back(nums[i]);
      }
    }
    for (int j = 0; j < n / 2; j++) // TC=O(N/2)
    {
      nums[2 * j] = pos[j];
      nums[2 * j + 1] = neg[j];
    }
    return nums; // TC=O(N)+O(N/2)
  }

  //---------------------------------OPTIMAL-------------------------------------------
  //---------------------------TC=O(N), SC=O(N)---------------------------------------

  vector<int> rearrangeArrayoptimal(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> result(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
      {
        result[posIndex] = nums[i];
        posIndex += 2;
      }
      else
      {
        result[negIndex] = nums[i];
        negIndex += 2;
      }
    }
    return result;
  }

  //-------------------------------(When size is not equal)--------------------- -----
  //----------------------------TC=O(N) SC=O(N)---------------------------------------

  vector<int> rearrangeArray(vector<int> &nums) // when size is not equal
  {
    int n = nums.size(), k = 0, j = 0;
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0)
      {
        pos.push_back(nums[i]);
      }
      else
      {
        neg.push_back(nums[i]);
      }
    }
    if (pos.size() > neg.size())
    {
      for (int i = 0; i < neg.size(); i++)
      {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
      }
      int index = 2 * neg.size();
      for (int i = neg.size(); i < pos.size(); i++)
      {
        nums[index] = pos[i];
        index++;
      }
    }
    else
    {
      for (int i = 0; i < pos.size(); i++)
      {
        nums[2 * i] = pos[i];
        nums[2 * i + 1] = neg[i];
      }
      int index = 2 * pos.size();
      for (int i = pos.size(); i < neg.size(); i++)
      {
        nums[index] = neg[i];
        index++;
      }
    }
    return nums;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {3, 4, -2, 5, -1, -7, -8};
  vector<int> result = sol.rearrangeArray(nums);
  vector<int> nums1 = {2, 5, -2, -1, 5, -9};
  vector<int> result2 = sol.rearrangeArrayoptimal(nums1);
  ;

  cout << "Sorted result: Size is equal ";
  for (auto it : result2)
    cout << it;

  cout << "Sorted result: Size is not equal ";
  for (auto it : result)
    cout << it;

  return 0;
}