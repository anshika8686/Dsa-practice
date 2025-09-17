#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

//------------------------------------------O(N^2)----------------------------------------
    int maxSubArraybetter(vector<int>& nums) 
    {
        int n=nums.size(),maxsum=0,sum=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                maxsum=max(maxsum,sum);
            }
        }
        return maxsum;
    }


//------------------------------------O(N)---------------------------------------------------
     int maxSubArrayoptimal(vector<int>& nums) 
    {
        int n=nums.size(),curr_sum=0,maxsum=INT_MIN; 
        // if(n==1){
        //     return nums[0];
        // }
        for(int i=0;i<n;i++){
         curr_sum+=nums[i];//keeps track of the current sum
         if(curr_sum<nums[i]){
            curr_sum=nums[i];// fresh start->starting of a new subarray if the past sum is smaller than current nums
         }
         maxsum=max(maxsum,curr_sum);
        }
        return maxsum;
    }

    void printmaxSubArrayoptimal(vector<int>& nums) 
    {
        int n=nums.size(),curr_sum=0,maxsum=INT_MIN; 
        int start,ansstart,ansend;
        for(int i=0;i<n;i++){
         curr_sum+=nums[i];//keeps track of the current sum
         if(curr_sum<nums[i]){
            curr_sum=nums[i];
            start=i;// fresh start->starting of a new subarray if the past sum is smaller than current nums
         }
         if(curr_sum>maxsum){
         maxsum=curr_sum;
         ansstart=start;
         ansend=i;
        }
    }
        cout<< "Maximum Subarray is:";
        for(int i=ansstart;i<=ansend;i++){
            cout<<endl<<nums[i];
        }
    }

};
int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int sum=sol.maxSubArrayoptimal(nums);
    cout << "Maximum sum is: "<<endl<<sum;
    sol.printmaxSubArrayoptimal(nums);
    return 0;
}
