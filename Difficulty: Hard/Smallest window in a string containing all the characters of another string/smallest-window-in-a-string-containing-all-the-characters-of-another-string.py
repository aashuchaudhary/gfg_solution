#User function Template for python3


class Solution:
    
    #Function to find the smallest window in the string s consisting
    #of all the characters of string p.
    def smallestWindow(self, s, p):
        len1 = len(s)
        len2 = len(p)
        
        if len1 < len2:
            return "-1"

        hash_str = [0] * 256
        hash_pat = [0] * 256

        for char in p:
            hash_pat[ord(char)] += 1

        start = 0
        start_index = -1
        min_len = float('inf')
        count = 0

        for j in range(len1):
            hash_str[ord(s[j])] += 1

            if hash_pat[ord(s[j])] != 0 and hash_str[ord(s[j])] <= hash_pat[ord(s[j])]:
                count += 1

            if count == len2:
                while hash_str[ord(s[start])] > hash_pat[ord(s[start])] or hash_pat[ord(s[start])] == 0:
                    if hash_str[ord(s[start])] > hash_pat[ord(s[start])]:
                        hash_str[ord(s[start])] -= 1
                    start += 1

                window_len = j - start + 1
                if min_len > window_len:
                    min_len = window_len
                    start_index = start

        if start_index == -1:
            return "-1"
        
        return s[start_index: start_index + min_len]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        ob = Solution()
        print(ob.smallestWindow(s,p))
# } Driver Code Ends