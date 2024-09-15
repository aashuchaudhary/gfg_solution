//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        long long result = 0;
        long long base = 1;

        while (n > 0) {
            long long digit = n % 9;  // Get the current digit in base-9
            result = result + digit * base;  // Map the base-9 digit to a decimal place
            base *= 10;  // Move to the next decimal place
            n /= 9;  // Move to the next base-9 digit
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends