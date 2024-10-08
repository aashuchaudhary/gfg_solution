//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int A[], int N, int M)
    {
        // code here
        // return minimum time
        
          long long start =0,end=0,mid,ans;
        for(int i=0;i<N;i++)
        {
            if(start<A[i])
            start=A[i];
            end+=A[i];
            
        }
        
        while(start<=end)
        {
            mid=start+(end-mid)/2;
            
            
            long long page=0,count=1;
            for(int i=0;i<N;i++)
            {
                page+=A[i];
                if(page>mid)
                {
                    count ++;
                    page=A[i];
                }
             }
            
            if(count<=M)
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
         }
            return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends