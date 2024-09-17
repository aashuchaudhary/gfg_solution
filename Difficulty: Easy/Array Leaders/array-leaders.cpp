//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
           vector<int> result;
        int max_so_far = arr[n - 1];  // The rightmost element is always a leader
        
        // Start from the rightmost element and iterate backwards
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] >= max_so_far) {
                result.push_back(arr[i]);  // This element is a leader
                max_so_far = arr[i];       // Update the max_so_far
            }
        }
        
        // Since we collected leaders in reverse order, we need to reverse the result array
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends