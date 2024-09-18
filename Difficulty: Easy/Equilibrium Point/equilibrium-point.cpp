//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
           int n = arr.size();
        
        // Edge case: If the array has only one element, that is the equilibrium point
        if (n == 1) {
            return 1; // 1-based index
        }

        long long totalSum = 0;
        long long leftSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // Traverse the array and find the equilibrium point
        for (int i = 0; i < n; i++) {
            // totalSum - leftSum - arr[i] gives the right sum
            if (leftSum == totalSum - leftSum - arr[i]) {
                return i + 1; // Return the equilibrium point (1-based index)
            }
            // Update leftSum by adding the current element
            leftSum += arr[i];
        }

        // If no equilibrium point is found, return -1
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends