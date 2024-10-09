//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int start = *max_element(arr, arr + N); // Start is the largest element in the array
        int end = accumulate(arr, arr + N, 0);  // End is the sum of all elements in the array
        int result = end;
        
        // Binary search to find the minimum possible maximum subarray sum
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Check if it's possible to split the array with this mid as the maximum sum
            if (canSplit(arr, N, K, mid)) {
                result = mid;  // If possible, store the result and try for a smaller maximum sum
                end = mid - 1;
            } else {
                start = mid + 1;  // Otherwise, increase the minimum possible sum
            }
        }
        
        return result; // Return the minimum possible maximum subarray sum
    }
    
    // Helper function to check if we can split the array into K or fewer subarrays with maximum sum <= mid
    bool canSplit(int arr[], int N, int K, int mid) {
        int subarrayCount = 1;  // We always start with one subarray
        int currentSum = 0;
        
        for (int i = 0; i < N; i++) {
            currentSum += arr[i];
            
            // If adding arr[i] exceeds the mid value, we create a new subarray
            if (currentSum > mid) {
                subarrayCount++;
                currentSum = arr[i];  // Start a new subarray with the current element
            }
            
            // If the number of subarrays exceeds K, return false
            if (subarrayCount > K) {
                return false;
            }
        }
        
        return true;  // If we can split within K subarrays, return true
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends