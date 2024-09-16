//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched

    int Binarysearch(int arr[], int start, int end, int X) {
        // Base Condition
        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;
        if (arr[mid] == X)
            return 1; // Return the index where the element is found
        else if (arr[mid] < X)
            return Binarysearch(arr, mid + 1, end, X);
        else
            return Binarysearch(arr, start, mid - 1, X);
    }

    int searchInSorted(int arr[], int N, int K) {
        // Your code here
        return Binarysearch(arr, 0, N - 1, K); // Corrected the parameter to use K instead of k
    }
};




//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;
    }

    return 0;
}

// } Driver Code Ends