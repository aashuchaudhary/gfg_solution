//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    int minIncrements(std::vector<int>& arr) {
        // Sort the array to handle duplicates in order
        std::sort(arr.begin(), arr.end());
        
        int increments = 0;
        
        // Iterate through the array starting from the second element
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i - 1]) {
                // Calculate the new unique value
                int newVal = arr[i - 1] + 1;
                
                // Add the number of increments required
                increments += newVal - arr[i];
                
                // Update the current element to the new unique value
                arr[i] = newVal;
            }
        }
        
        return increments;
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
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends