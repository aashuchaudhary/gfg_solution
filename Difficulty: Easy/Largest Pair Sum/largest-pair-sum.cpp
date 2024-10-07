//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // Initialize the first and second maximums
    int first_max = INT_MIN, second_max = INT_MIN;

    // Traverse the array to find the two largest elements
    for (int num : arr) {
        if (num > first_max) {
            second_max = first_max;  // Update second_max
            first_max = num;         // Update first_max
        } else if (num > second_max) {
            second_max = num;        // Update second_max if it's smaller than first_max but larger than second_max
        }
    }

    // Return the sum of the two largest numbers
    return first_max + second_max;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends