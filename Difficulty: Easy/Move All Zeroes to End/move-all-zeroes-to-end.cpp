//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(std::vector<int>& arr) {
        int n = arr.size();
        int j = 0; // Pointer to track the next position for non-zero elements
        
        // Iterate through the array
        for (int i = 0; i < n; ++i) {
            if (arr[i] != 0) {
                std::swap(arr[i], arr[j]);
                ++j; // Increment position for non-zero elements
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends