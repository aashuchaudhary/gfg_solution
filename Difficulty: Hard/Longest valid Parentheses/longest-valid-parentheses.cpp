//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
     
        // Stack to store indices
        stack<int> stk;
        // Initialize the stack with a base for valid substrings
        stk.push(-1);
        int max_len = 0; // To store the maximum length of valid parentheses

        // Traverse the string
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                // Push index of the opening parenthesis
                stk.push(i);
            } else {
                // Pop the previous opening parenthesis index
                stk.pop();

                // Check if stack is empty
                if (stk.empty()) {
                    stk.push(i); // Set the base for next valid substring
                } else {
                    // Calculate the length of valid substring
                    max_len = max(max_len, i - stk.top());
                }
            }
        }
        return max_len;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends