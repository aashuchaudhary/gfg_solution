//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        
             int n = str.length();

        // For digit less than or equal to 5
        if (str[n - 1] <= '5') {
            str[n - 1] = '0';
            return str;
        }

        // Set the last digit to 0
        str[n - 1] = '0';

        // Handle cases like "999"
        int i = n - 2;
        while (i >= 0 && str[i] == '9') {
            str[i] = '0';
            i--;
        }

        // If all digits were '9', prepend '1'
        if (i < 0) str = '1' + str;
        else str[i]++;
        return str;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends