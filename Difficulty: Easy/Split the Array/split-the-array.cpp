//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countgroup(vector<int>& arr) {
         int n = arr.size();
        int mod = 1e9 + 7;

        // Calculate XOR of all elements
        int xorSum = 0;
        for (int num : arr) {
            xorSum ^= num;
        }

        // If XOR is not zero, return 0 (no valid groups possible)
        if (xorSum != 0) return 0;

        // Calculate 2^(n-1) % mod
        long long result = 1;
        for (int i = 0; i < n - 1; i++) {
            result = (result * 2) % mod;
        }

        // Subtract 1 and return the result
        return (result - 1 + mod) % mod;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends