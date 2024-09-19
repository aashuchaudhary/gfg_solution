//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		
		// Helper function to find the first occurrence of X
    int findFirstOccurrence(int arr[], int n, int x) {
        int start = 0, end = n - 1, firstOccurrence = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                firstOccurrence = mid; // record the first occurrence
                end = mid - 1;  // keep searching in the left half
            }
            else if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return firstOccurrence;
    }

    // Helper function to find the last occurrence of X
    int findLastOccurrence(int arr[], int n, int x) {
        int start = 0, end = n - 1, lastOccurrence = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                lastOccurrence = mid; // record the last occurrence
                start = mid + 1;  // keep searching in the right half
            }
            else if (arr[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return lastOccurrence;
    }
     // Main function to count occurrences of X
    int count(int arr[], int n, int x) {
        int first = findFirstOccurrence(arr, n, x);
        if (first == -1) 
            return 0;  // X is not present in the array

        int last = findLastOccurrence(arr, n, x);
        return last - first + 1;
    }
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends