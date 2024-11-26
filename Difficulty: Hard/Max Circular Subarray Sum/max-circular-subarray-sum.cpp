//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Initialize variables
        int maxSubarraySum = arr[0], currentMax = arr[0];
        int minSubarraySum = arr[0], currentMin = arr[0];
        int totalSum = arr[0];

        // Traverse the array
        for (int i = 1; i < n; i++) {
            totalSum += arr[i];

            // Calculate max subarray sum using Kadane's Algorithm
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSubarraySum = max(maxSubarraySum, currentMax);

            // Calculate min subarray sum using Kadane's Algorithm
            currentMin = min(arr[i], currentMin + arr[i]);
            minSubarraySum = min(minSubarraySum, currentMin);
        }

        // Handle the edge case where all elements are negative
        if (maxSubarraySum < 0) {
            return maxSubarraySum;
        }

        // Calculate the maximum circular subarray sum
        int circularSum = totalSum - minSubarraySum;

        // Return the maximum of the two cases
        return max(maxSubarraySum, circularSum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends