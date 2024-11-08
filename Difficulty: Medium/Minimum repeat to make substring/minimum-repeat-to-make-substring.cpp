//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    static int minRepeats(string s1, string s2) {
        string temp = s1;
        int cnt = 1;

        // Repeat s1 until its length is at least the length of s2
        while (s1.size() < s2.size()) {
            s1 += temp;
            cnt++;
        }

        // Check if s2 is a substring of the repeated s1
        if (s1.find(s2) != string::npos) return cnt;

        // Add one more repetition and check again
        s1 += temp;
        cnt++;
        if (s1.find(s2) != string::npos) return cnt;

        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends