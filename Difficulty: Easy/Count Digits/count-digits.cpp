//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int cnt =0;
        int n=N;
        while(n!=0)
        {
            int lastDigit=n%10;
           if(lastDigit!=0 && N%lastDigit ==0) 
           {
               cnt++;
           }
           n=n/10;
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends