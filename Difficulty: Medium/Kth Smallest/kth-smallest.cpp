//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
     // Partition function to partition the array around a pivot
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;        // Index of the smaller element

        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        // Swap the pivot element with the element at i+1
        swap(arr[i + 1], arr[high]);
        return i + 1;  // Return the partition index
    }

    // Quickselect function to find the k-th smallest element
    int quickSelect(vector<int>& arr, int low, int high, int k) {
        if (low <= high) {
            int pi = partition(arr, low, high);  // Partition index

            // If partition index is the k-th position, return the element
            if (pi == k - 1) {
                return arr[pi];
            }
            // If partition index is greater, recur for the left part
            else if (pi > k - 1) {
                return quickSelect(arr, low, pi - 1, k);
            }
            // Else recur for the right part
            else {
                return quickSelect(arr, pi + 1, high, k);
            }
        }
        return -1;  // This should never be reached if k is valid
    }
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    
    // Function to find the k-th smallest element in the array
    int kthSmallest(vector<int>& arr, int k) {
        int n = arr.size();
        return quickSelect(arr, 0, n - 1, k);  // Call quickSelect to get the k-th smallest
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends