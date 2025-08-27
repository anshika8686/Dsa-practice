#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // --------------------------------------------------
    // Brute Force Approach (Sorting)
    // TC: O(n log n), SC: O(1)
    // --------------------------------------------------
    int getSecondLargestBrute(int *arr, int n) {
        if (n < 2) return -1;  // not enough elements
        sort(arr, arr+n); // O(n log n)
        for (int i = n-2; i >= 0; i--) { // O(n)
            if (arr[i] != arr[n-1]) {
                return arr[i];
            }
        }
        return -1; // if all elements are same
    }

    // --------------------------------------------------
    // Better Approach (Two-Pass)
    // 1st pass: find largest
    // 2nd pass: find element < largest
    // TC: O(2n) = O(n), SC: O(1)
    // --------------------------------------------------
    int getSecondLargestTwoPass(int *arr, int n) {
        if (n < 2) return -1;

        int largest = -1, seclargest = -1;
        for (int i = 0; i < n; i++) {
            largest = max(largest, arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] < largest && arr[i] > seclargest) {
                seclargest = arr[i];
            }
        }
        return seclargest;
    }

    // --------------------------------------------------
    // Optimized Approach (One-Pass)
    // TC: O(n), SC: O(1)
    // --------------------------------------------------
    int getSecondLargestOnePass(int *arr, int n) {
        if (n < 2) return -1;

        int largest = -1, seclargest = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                seclargest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > seclargest) {
                seclargest = arr[i];
            }
        }
        return seclargest;
    }
};

// --------------------------------------------------
int main() {
    Solution sol;
    int arr[] = {2, 4, 5, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Brute: " << sol.getSecondLargestBrute(arr, n) << endl;
    cout << "Better:" << sol.getSecondLargestTwoPass(arr, n) << endl;
    cout << "Optimised: " << sol.getSecondLargestOnePass(arr, n) << endl;
    return 0;
}
