//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int currentSum = 0;
        int maxSum = arr[0]; // Initialize to the first element for edge cases

        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            maxSum = max(maxSum, currentSum); // Update maxSum
            
            // Reset currentSum if it becomes negative
            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends