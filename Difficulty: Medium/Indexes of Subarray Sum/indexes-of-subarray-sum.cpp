//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
            int left = 0;  // Start of the subarray
        long long current_sum = 0;

        // Iterate through the array
        for (int right = 0; right < n; ++right) {
            // Add the current element to the running sum
            current_sum += arr[right];

            // Shrink the window from the left if current_sum exceeds the target sum
            while (current_sum > s && left < right) {
                current_sum -= arr[left];
                left++;
            }

            // If the current sum matches the desired sum, return the 1-based indexes
            if (current_sum == s) {
                return {left + 1, right + 1};  // 1-based indexing
            }
        }

        // If no subarray is found, return -1
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends