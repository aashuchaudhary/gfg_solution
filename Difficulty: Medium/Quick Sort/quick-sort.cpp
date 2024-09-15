//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int start, int end)
    {
        // code here
        // Base Case
        if(start >= end)
        return;
        
        int pivot = partition(arr, start, end);
        // Left
        quickSort(arr, start, pivot - 1);
        // Right
        quickSort(arr, pivot + 1,end);
    }
    
    public:
    int partition (int arr[], int start, int end)
    {
       // Your code here
       int pos = start;
       for(int i = start; i <= end; i++)
       {
           if(arr[i] <= arr[end])
           {
               
           swap(arr[i],arr[pos]);
           pos++;
           }
       }
       return pos -1;
    }
};



//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends