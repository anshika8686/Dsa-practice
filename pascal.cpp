#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>matrix;
        int r;
        for(int i=1;i<=numRows;i++){//O(numRows)
            int r=0,element=0;
            vector<int>temp;
           for(int j=1;j<=i;j++){//O(numRows)
            int n=i-1;
            int r=j-1;
           int  element=calculate(n,r);
            temp.push_back(element);
           }
           matrix.push_back(temp);//O()-> to return answer
        }
        return matrix;
    }

      int calculate(int row,int col)
    {   
         int res=1;
        for(int i=0;i<col;i++){
         res=res*(row-i);//o(col)
         res=res/(i+1);
        }
        return res;
        
    }

vector<vector<int>> generateoptimal(int numRows) 
    {
        vector<vector<int>>matrix;
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);//O(N2)
          for(int j=1;j<i;j++){
             row[j]=matrix[i-1][j-1]+matrix[i-1][j];
          }
          matrix.push_back(row);
        }
        return matrix;
    }
};

int main(){
  Solution Sol;
  int numRows=5;
  vector<vector<int>> ans=generateoptimal(numRows);
  for(auto &it:ans){
    cout<< 
  }

}