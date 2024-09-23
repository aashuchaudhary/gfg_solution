//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int repeating = -1, missing = -1;

        // Mark visited positions as negative
        for (int i = 0; i < n; ++i) {
            int idx = abs(arr[i]) - 1;
            if (arr[idx] < 0) {
                repeating = abs(arr[i]); // Found repeating number
            } else {
                arr[idx] = -arr[idx]; // Mark as visited
            }
        }

        // Find missing number
        for (int i = 0; i < n; ++i) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends