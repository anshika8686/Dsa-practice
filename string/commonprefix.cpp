#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    int n = strs.size();
    string ans = "";
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[n - 1];
    int n1 = first.length();
    int n2 = last.length();
    int mini = min(n1, n2);
    for (int i = 0; i < mini; i++)
    {
      if (first[i] != last[i])
      {
        break;
      }
      ans = ans + first[i];
    }
    return ans;
  }
};
int main()
{
  Solution sol;
  vector<string> strs = {"flower", "flow", "flight"};
  string ans = sol.longestCommonPrefix(strs);
  cout << "Prefix is" << endl
       << ans;
}
