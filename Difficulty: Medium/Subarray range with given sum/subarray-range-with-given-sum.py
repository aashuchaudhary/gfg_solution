#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    # Function to count the number of subarrays which adds to the given sum.
    def subArraySum(self, arr, tar):
        count, current_sum = 0, 0
        prefix_sums = {0: 1}  # Dictionary to store prefix sums and their frequency
        
        for num in arr:
            current_sum += num
            if current_sum - tar in prefix_sums:
                count += prefix_sums[current_sum - tar]
            if current_sum in prefix_sums:
                prefix_sums[current_sum] += 1
            else:
                prefix_sums[current_sum] = 1
        
        return count  # Ensure the result is returned here

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        tar= int(input())
        ob = Solution()
        res = ob.subArraySum(arr,tar)
        print(res)
        # print("~")
        t -= 1


# } Driver Code Ends