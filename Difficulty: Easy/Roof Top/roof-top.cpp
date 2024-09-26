//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
       
        int max_steps = 0; 
        int current_steps = 0; 

        // Traverse through the array
        for (int i = 1; i < arr.size(); i++) {
            // If current building is taller than  previous one
            if (arr[i] > arr[i - 1]) {
                current_steps++; // Increase the count of consecutive steps
                max_steps = max(max_steps, current_steps); // Update max_steps if needed
            } else {
                current_steps = 0; // Reset the current steps counter
            }
        }
        return max_steps;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.maxStep(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends