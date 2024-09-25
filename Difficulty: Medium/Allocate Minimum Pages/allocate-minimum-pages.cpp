//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution 
{
  public:
   // Function to find the minimum number of pages.
    long long findPages(int N, int arr[], int M) 
    {
        // If there are more students than books, return -1
        if (M > N)
            return -1;
        
        // Initialize start and end values for binary search
        long long start = 0, end = 0, ans = -1, mid;
        for (int i = 0; i < N; i++)
        {
            start = max(start, (long long)arr[i]); // Start should be the max element in arr
            end += arr[i];  // End should be the sum of all elements in arr
        }
        
        // Binary search
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            long long pages = 0;
            int count = 1;
            
            // Allocate books to students
            for (int i = 0; i < N; i++)
            {
                pages += arr[i];
                
                // If pages exceed mid, allocate to the next student
                if (pages > mid)
                {
                    count++;
                    pages = arr[i];
                }
            }
            
            // If count is less than or equal to M, update answer and search left half
            if (count <= M)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        
        // Return the final answer
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends