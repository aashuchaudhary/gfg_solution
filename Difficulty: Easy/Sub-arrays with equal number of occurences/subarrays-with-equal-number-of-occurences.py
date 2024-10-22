#User function Template for python3

from collections import defaultdict
from typing import List
class Solution:
    def sameOccurrence(self, arr, x, y):
        count_x, count_y = 0, 0
        res = 0
        diff_map = defaultdict(int)
        diff_map[0] = 1  # Initial condition to handle the subarray starting from index 0
        
        for num in arr:
            if num == x:
                count_x += 1
            elif num == y:
                count_y += 1

            diff = count_x - count_y

            if diff in diff_map:
                res += diff_map[diff]

            diff_map[diff] += 1

        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        x = int(input().strip())
        y = int(input().strip())
        ob = Solution()
        ans = ob.sameOccurrence(arr, x, y)
        print(ans)
        tc -= 1

# } Driver Code Ends