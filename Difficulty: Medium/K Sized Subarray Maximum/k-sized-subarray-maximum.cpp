//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
         vector<int> result;
        deque<int> dq; // Stores indices of array elements
        
        for (int i = 0; i < arr.size(); i++) {
            // Remove elements out of this window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove elements smaller than the current element from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add current element's index at the back of the deque
            dq.push_back(i);
            
            // Append the maximum element for the current window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends