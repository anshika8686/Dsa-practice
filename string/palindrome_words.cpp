#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string reverseWords(string s)
  {
    int n = s.length();
    string ans = "", word = "";
    reverse(s.begin(), s.end());
    s.push_back(' ');
    for (int i = 0; i <= n; i++)
    {
      if (s[i] != ' ')
      {
        word = word + s[i];
      }
      else
      {
        if (word.length() > 0)
        {
          reverse(word.begin(), word.end());
          ans = ans + " " + word;
          word.clear();
        }
      }
    }
    return ans.substr(1);
  }
};
int main()
{
  Solution sol;
  string s = "My cat is brown in colour";
  string ans = sol.reverseWords(s);
  cout << "Palindrome words" << endl
       << ans;
}