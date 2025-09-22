#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1, j = n - 1, k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
      if (nums1[i] <= nums2[j])
      {
        nums1[k] = nums2[j];
        j--;
        k--;
      }
      else
      {
        nums1[k] = nums1[i];
        i--;
        k--;
      }
    }
    while (j >= 0)
    {
      nums1[k] = nums2[j];
      k--;
      j--;
    }
  }
};
int main()
{
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  int m = 3, n = 3;
  sol.merge(nums1, m, nums2, n);
  cout << "Array is" << endl;
  for (auto &it : nums1)
  {
    cout << it << " ";
  }
  return 0;
}
