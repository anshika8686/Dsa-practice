#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//-------------------------------------TC=O(N^2) SC=O(1)--------------------------------------

int majorityElementbrute(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return -1;
}

//----------------------------------TC=O(N) SC=O(N)---------------------------------------)
    int majorityElementbetter(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hashmap;
        for(int i=0;i<n;i++)
        {
            hashmap[nums[i]]++;
        }
        for(auto it:hashmap)
        {
            int number=it.first;
             int count=it.second;
            if(count>n/2){
                return number;
            }
        }
        return -1;
    }

    //-------------------------------TC=O(N) SC=O(1)------------------------------------------

    int majorityElementoptimal(vector<int>& nums) {
        int n=nums.size();
        int element=nums[0],count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                element=nums[i];
            }
             else if(element==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};
int main()
{
    Solution sol;
    vector<int>arr = {2,1,2,1,1,2,2,2};

    cout << "Brute: " << sol.majorityElementbrute(arr) << endl;
    cout << "Better:" << sol.majorityElementbetter(arr) << endl;
    cout << "Optimised: " << sol.majorityElementoptimal(arr) << endl;
    return 0;
}