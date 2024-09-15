//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
	string is_palindrome(int n) {
        int revNum = 0;
        int dup = n;

        while (n != 0) {
            int ld = n % 10;
            n = n / 10;

            if (revNum > INT_MAX / 10 || revNum < INT_MIN / 10) {
                return "No"; // Indicates numeric overflow
            }

            revNum = (revNum * 10) + ld;
        }

        if (dup == revNum) {
            return "Yes";
        } else {
            return "No";
        }
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends