//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        int n =  arr.size();
        int start=0, end = n - 1;
        int FirstIndex=-1;
        
        // Binary search
        while(start <= end){
            int mid =start + (end-start)/2;
            // Mid zero the first count
            if(arr[mid]==0 && (mid == 0 || arr[mid-1]==1))
            return n-mid;
            else if (arr[mid]==1)
            start=mid+1;
            else end = mid-1;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.countZeroes(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends