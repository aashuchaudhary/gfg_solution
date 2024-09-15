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
    void merge(int arr[], int start, int mid, int end)
    {
         // Your code here
        //  temp is size of array
        
         vector<int>temp(end - start + 1);
         int left = start, right = mid+1, index = 0;
         while( left <=mid && right <= end)
         {
             if(arr[left] <= arr[right])
             {
                 temp[index]=arr[left];
                 index++, left++ ;
             }
             else
             {
                 temp[index]=arr[right];
                 index++, right++ ;
                 
             }
         }
        //  left ramaining 
        while(left <= mid)
        {
             temp[index]=arr[left];
                 index++, left++ ;
        }
        // right remaining
        while(right <= end)
        {
            temp[index]=arr[right];
                 index++, right++ ;
            
        }
        index = 0;
        
        while(start<=end)
        {
            arr[start] =temp[index];
            start++,index++;
        }
        
    }
    public:
    void mergeSort(int arr[], int start, int end)
    {
        //code here
        if(start == end)
        return;
        int mid = start + (end - start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
};


//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends