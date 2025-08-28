#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate an array by d elements in anti-clockswise(left) direction.

    void rotateArrbrute(vector<int>& arr, int d) {
         int n=arr.size();
         int temp;
        for(int j=0;j<d;j++){//O(D)
             temp=arr[0];
             for(int i=1;i<n;i++){//O(N*D)
                 arr[i-1]=arr[i];
             }
             arr[n-1]=temp;
         }
     }
    void rotateArroptimise(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Handle cases where d > n

        // Step 1: Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Step 2: Reverse remaining n-d elements
        reverse(arr.begin() + d, arr.end());

        // Step 3: Reverse entire array
        reverse(arr.begin(), arr.end());
    }
};

int main() {
    int n, d;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of rotations: ";
    cin >> d;

    Solution obj;
    obj.rotateArrbrute(arr, d);
    cout << "Array after rotation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
