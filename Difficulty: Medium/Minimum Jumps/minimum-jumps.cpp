//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
       int n = arr.size();
        if (n == 0 || arr[0] == 0) return -1;  // Can't move from the start
        
        int jumps = 0;  // Number of jumps made
        int maxReach = 0;  // The farthest position reachable with the current number of jumps
        int endOfCurrentJump = 0;  // End of the range covered by the current jump

        for (int i = 0; i < n - 1; ++i) {
            maxReach = max(maxReach, i + arr[i]);
            
            // If we've reached the end of the current jump range
            if (i == endOfCurrentJump) {
                jumps++;
                endOfCurrentJump = maxReach;
                
                // If the end of the current jump range covers the last index
                if (endOfCurrentJump >= n - 1) {
                    return jumps;
                }
            }
        }
        
        return -1;  // If we exit the loop without reaching the end
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends