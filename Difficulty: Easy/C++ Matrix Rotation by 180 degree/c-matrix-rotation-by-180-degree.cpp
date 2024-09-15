//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void rotate(vector<vector<int> >& mat) {
        // Code here
       int n=mat[0].size();
       int k=0,max=(n*n)/2;
       for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
       {
           k++;
           int temp=mat[n-1-i][n-1-j];
           mat[n-1-i][n-1-j]=mat[i][j];
           mat[i][j]=temp;
           if(k==max)
           return;
       }
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.rotate(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends