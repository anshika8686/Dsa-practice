#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    
    //----------------------------------------Brute-------------------------------------------
    //----------------------------------TC=O(N^2)->SC=O(1)---------------------------------------
    
    void sortColorsbrute(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
    }
        

    //---------------------------------Better-------------------------------------------
    //---------------------------TC=O(2N), SC=O(1)---------------------------------------
    void sortColorsbetter(vector<int>& nums) 
    {
    int n=nums.size(),count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
            count0++;}
            else if(nums[i]==1){
            count1++;}
            else{
            count2++;}
        }
        for(int i=0;i<count0;i++){
         nums[i]=0;
        }
        for(int i=count0;i<(count0+count1);i++){
            nums[i]=1;
        }
        for(int i=(count0+count1);i<(count0+count1+count2);i++){
            nums[i]=2;
        }
    }
    //----------------------OPTIMAL(DUTCH NATIONAL FLAG ALGORITHM---------------------------------------------
    //----------------------------TC=O(N) SC=O(1)---------------------------------------
    void sortColorsoptimal(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
        if(nums[mid]==0){
        swap(nums[low],nums[mid]);
        low++; mid++;
        }
        else if(nums[mid]==1){
        mid++;
        }
        else{
        swap(nums[high],nums[mid]);
        high--;
        }
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums = {0, 2, 1, 0, 1, 1, 2, 2, 0, 0};
    sol.sortColorsoptimal(nums);

    cout << "Sorted result: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}