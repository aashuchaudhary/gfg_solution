//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i] < v[i+1])
            {
                idx=i;
                break;
            }
        }

        if(idx==-1)
        {
            reverse(v.begin(),v.end());
            return;
        }
        
        reverse(v.begin()+idx+1,v.end());

        int j=idx;
        
        while(j<n-1)
        {
            if(v[j]>v[idx])
            break;
            j++;
        }

        int t = v[idx];
        v[idx] = v[j];
        v[j]    = t;

        return;
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
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends