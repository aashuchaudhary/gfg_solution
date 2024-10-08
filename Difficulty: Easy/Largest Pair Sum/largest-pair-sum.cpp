//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
       
    int first_max = INT_MIN, second_max = INT_MIN;

    
    for (int i= 0; i< arr.size(); i++) {
        if (arr[i]> first_max) {
            second_max = first_max;  //update second
            first_max = arr [i];      //  update first
        } else if (arr[i] > second_max) {
            second_max = arr[i];      //upadte second   
    }
}
  
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