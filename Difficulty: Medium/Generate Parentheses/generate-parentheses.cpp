//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void parenthesis(int n, int left, int right, vector<string>&ans, string &temp)
    {
        // Base case
        if(left+right == 2*n)
        {
            ans.push_back(temp);
            return;
        }
        
        // left parenthesis
        if(left < n)
        {
            temp.push_back('(');
            parenthesis(n, left + 1, right, ans, temp);
            temp.pop_back();
        }
        // Right parenthesis
        if(right < left)
        {
            temp.push_back(')');
            parenthesis(n, left, right + 1, ans, temp);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
         string temp;
        parenthesis(n,0,0,ans,temp);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends