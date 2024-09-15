//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        vector<int> count(256, 0);
    int first = 0, second = 0, len = INT_MAX, diff = 0;

    // Calculate all the unique characters
    while (first < str.size()) {
        if (count[str[first]] == 0)
            diff++;

        count[str[first]]++;
        first++;
    }

    // Reset the count array
    fill(count.begin(), count.end(), 0);

    first = 0;

    while (second < str.size()) {
        // While diff is not zero
        while (diff && second < str.size()) {
            if (count[str[second]] == 0)
                diff--;

            count[str[second]]++;
            second++;
        }

        // Update the minimum length
        len = min(len, second - first);

        // While diff is not 1
        while (diff != 1) {
            len = min(len, second - first);
            count[str[first]]--;

            if (count[str[first]] == 0)
                diff++;

            first++;
        }
    }

    return len == INT_MAX ? 0 : len;
    }
};


//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends