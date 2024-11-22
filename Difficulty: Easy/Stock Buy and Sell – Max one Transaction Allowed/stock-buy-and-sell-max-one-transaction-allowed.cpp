//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int minPrice = INT_MAX; // Track the minimum price seen so far
        int maxProfit = 0;      // Track the maximum profit

        for (int price : prices) {
            minPrice = min(minPrice, price);            // Update the minimum price
            maxProfit = max(maxProfit, price - minPrice); // Update the maximum profit
        }

        return maxProfit;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends