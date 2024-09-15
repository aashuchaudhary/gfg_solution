//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size(); // Fixed error here by removing "/"
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // Distance array initialized with infinity
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Directions array to explore four possible moves (up, down, left, right)
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Start from the top-left corner
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while (!pq.empty()) {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // If we have reached the bottom-right cell
            if (x == n - 1 && y == n - 1)
                return cost;

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];

                // Check boundaries
                if (newX >= 0 && newY >= 0 && newX < n && newY < n) {
                    int newCost = cost + grid[newX][newY];
                    // If a cheaper cost is found, update and push it into the priority queue
                    if (newCost < dist[newX][newY]) {
                        dist[newX][newY] = newCost;
                        pq.push({newCost, {newX, newY}});
                    }
                }
            }
        }
        return dist[n - 1][n - 1]; // Return the minimum cost for the bottom-right cell
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends