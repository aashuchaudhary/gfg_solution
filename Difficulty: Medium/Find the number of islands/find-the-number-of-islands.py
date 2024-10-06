#User function Template for python3

class Solution:
    def numIslands(self, grid):
        islands = 0
        rows = len(grid)
        cols = len(grid[0]) if rows > 0 else 0
        visited = set()

        # Directions for 8 possible moves (horizontal, vertical, diagonal)
        directions = [
            (1, 0), (-1, 0), (0, 1), (0, -1),
            (1, 1), (1, -1), (-1, 1), (-1, -1)
        ]

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and (r, c) not in visited:  # Change '1' to 1
                    islands += 1
                    self.bfs(grid, r, c, visited, directions, rows, cols)

        return islands        

    def bfs(self, grid, r, c, visited, directions, rows, cols):
        queue = [(r, c)]
        visited.add((r, c))

        while queue:
            row, col = queue.pop(0)

            for dr, dc in directions:
                nr, nc = row + dr, col + dc
                if 0 <= nr < rows and 0 <= nc < cols and grid[nr][nc] == 1 and (nr, nc) not in visited:  # Change '1' to 1
                    queue.append((nr, nc))
                    visited.add((nr, nc))


#{ 
 # Driver Code Starts
# Driver code
if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])
        obj = Solution()
        print(obj.numIslands(grid))

# } Driver Code Ends