#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def modifyAndRearrangeArr(self, arr):
        n = len(arr)
        
        # Step 1: Modify the array by merging adjacent equal non-zero values
        for i in range(n - 1):
            if arr[i] != 0 and arr[i] == arr[i + 1]:
                arr[i] *= 2
                arr[i + 1] = 0
        
        # Step 2: Move all non-zero values to the front, and zeros to the end
        result = []
        for num in arr:
            if num != 0:
                result.append(num)
        
        # Fill the remaining spaces with 0s
        result += [0] * (n - len(result))
        
        return result



#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.modifyAndRearrangeArr(arr)
        print(*ans)
        t -= 1


# } Driver Code Ends