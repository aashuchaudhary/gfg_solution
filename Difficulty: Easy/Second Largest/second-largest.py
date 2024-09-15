#User function Template for python3
class Solution:
    def print2largest(self, arr):
        # Code Here
        ans = -1
        Second = -1
        
        
        for num in arr:
            if num >ans:
                ans = num
                
        for num in arr:
            if num != ans and num >Second:
                Second  = num
                 
        return Second
        





#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.print2largest(arr)
        print(ans)

# } Driver Code Ends