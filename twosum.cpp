#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    //----------------------------------------Brute-------------------------------------------
    //----------------------------------TC=O(N^2)->SC=O(1)---------------------------------------
    vector<int> twoSumbrute(vector<int>& nums, int target) 
    {
       int n=nums.size();
       for(int i=0;i<n;i++){//O(N)
        for(int j=i+1;j<n;j++){//O(N)
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
       }
       return {-1,-1}; 
    }
    //---------------------------------Better-------------------------------------------
    //---------------------------TC=O(N), SC=O(N)---------------------------------------

    vector<int> twoSum(vector<int>& nums, int target) 
    {
       int n=nums.size();
       map<int,int>hashmap;
       for(int i=0;i<n;i++)//tc= O(n)
       {
         int rem=target-nums[i];
         if(hashmap.find(rem)!=hashmap.end()){//sc=O(n)
         return {i,hashmap[rem]};
       }
       hashmap.insert({nums[i],i});
    }
    return {-1,-1};
    }
    //--------------------------------------------------------------------------
};
int main()
{
    Solution sol;
    vector<int>nums={2,7,11,15};
    int target=18;
    vector<int>res=sol.twoSumbrute(nums,target);
    cout << "Brute result: [" << res[0] << ", " << res[1] << "]" << endl;
}