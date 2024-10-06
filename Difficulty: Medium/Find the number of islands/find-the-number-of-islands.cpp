//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int n,m;
//   Creting bector to store all 8 directions
vector<vector<int>>dir {{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};

void solve(vector<vector<char>>& grid,int i ,int j){
    // BAse case
    // if all element of an ilang become zero the return it,or it will be out of bond or lecc then i,j and greater then n,m.
    
    if(i < 0 || j < 0 ||i>= n ||j >=m ||grid[i][j]=='0')
    return;
    
    // Got coordinate make zero, and then check the in all 8 direction
    grid[i][j] = '0';
    for(auto &it:dir){
        // New coordinates
        int newi = i + it[0];
        int newj = j + it[1];
        
        // check for new index and check around the new index recursively.
        // we can solve and update new index.
        solve(grid,newi,newj);
        
    }
}
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
       n = grid.size();
       m = grid[0].size();
       int count  = 0;
       
       for(int i = 0; i < n; i++)
       {
           for(int j = 0; j< m; j++)
           {
            //   If we get the element = 1, then we  delete  island and incease the count.
            if(grid[i][j] == '1')
            {
                solve(grid,i,j);
                count++;
            }
           }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends