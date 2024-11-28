//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0, sign = 1;
        long ans = 0;

        // Skip leading whitespaces
        while (s[i] == ' ') i++;

        // Check for sign
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process numeric part
        while (s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');

            // Clamp the value within the 32-bit signed integer range
            if (sign * ans >= INT_MAX) return INT_MAX;
            if (sign * ans <= INT_MIN) return INT_MIN;

            i++;
        }

        // Return the final value
        return (int)(sign * ans);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends