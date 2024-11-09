//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string minSum(vector<int> &arr) {
        string n1, n2;
        sort(arr.begin(), arr.end());
        
        // Split numbers between n1 and n2 to form two minimum possible numbers
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) 
                n1 += to_string(arr[i]);
            else 
                n2 += to_string(arr[i]);
        }

        // Reverse both strings for easier addition from the least significant digit
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        
        string ans;
        int i = 0, j = 0;
        int carry = 0;

        // Add numbers digit by digit
        while (i < n1.size() || j < n2.size() || carry) {
            int sum = carry;
            if (i < n1.size()) sum += n1[i++] - '0';
            if (j < n2.size()) sum += n2[j++] - '0';

            carry = sum / 10;
            ans += to_string(sum % 10);
        }

        // Remove trailing zeroes if any, then reverse result
        while (ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        
        return ans.empty() ? "0" : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends