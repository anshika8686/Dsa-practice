#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //-----------------------tc=O(NLOGN) SC=O(N)-------------------------------------
    vector<vector<int>> mergebrute(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); // O(nlogn)
        for (int i = 0; i < n; i++)
        { // O(n)
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && end <= ans.back()[1]) // this interval is already merged
                continue;                             // skip this iteration
            for (int j = i + 1; j < n; j++)
            { // o(n)
                if (intervals[j][0] <= end)
                {                                    // whether intervals are overlapping or not
                    end = max(end, intervals[j][1]); // to take the max end of that overlapping material
                }
                else
                {
                    break; // no need to check further as we have already sorted it
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }

    //----------------------------------tc=O(nlogn) sc=O(n)----------------------------------

    vector<vector<int>> mergeoptimal(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); // O(nlogn)
        for (int i = 0; i < n; i++)
        { // O(n)
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (ans.empty())
            {
                ans.push_back({start, end});
            }
            else
            {
                int last = ans.size() - 1;
                if (start <= ans[last][1])
                {
                    end = max(end, ans[last][1]);
                    ans[last] = {ans[last][0], end};
                }
                else
                {
                    ans.push_back({start, end});
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> nums = {{0, 2}, {1, 4}, {3, 5}};
    vector<vector<int>> ans = sol.mergeoptimal(nums);

    cout << "Intervals are:" << endl;
    for (auto &it : ans)
    {
        cout << "[" << it[0] << "," << it[1] << "] ";
    }
    cout << endl;
    return 0;
}