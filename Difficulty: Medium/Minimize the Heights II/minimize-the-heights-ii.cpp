//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
         int n = arr.size();
        if (n == 1) return 0;

        // Sort the array
        sort(arr.begin(), arr.end());

        // Initialize the difference between max and min heights
        int ans = arr[n - 1] - arr[0];

        // Consider the smallest and largest after modifications
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Traverse the array and try modifying each element
        for (int i = 0; i < n - 1; i++) {
            int min_height = min(smallest, arr[i + 1] - k);
            int max_height = max(largest, arr[i] + k);
            if (min_height < 0) continue; // Ignore if height becomes negative
            ans = min(ans, max_height - min_height);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends