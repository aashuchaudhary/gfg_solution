//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string smallestWindow(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        
        if (len1 < len2) return "-1";

        vector<int> hash_str(256, 0);
        vector<int> hash_pat(256, 0);

        for (int i = 0; i < len2; i++)
            hash_pat[p[i]]++;

        int start = 0, start_index = -1, min_len = INT_MAX, count = 0;

        for (int j = 0; j < len1; j++) {
            hash_str[s[j]]++;

            if (hash_pat[s[j]] != 0 && hash_str[s[j]] <= hash_pat[s[j]])
                count++;

            if (count == len2) {
                while (hash_str[s[start]] > hash_pat[s[start]] || hash_pat[s[start]] == 0) {
                    if (hash_str[s[start]] > hash_pat[s[start]])
                        hash_str[s[start]]--;
                    start++;
                }

                int window_len = j - start + 1;
                if (min_len > window_len) {
                    min_len = window_len;
                    start_index = start;
                }
            }
        }

        if (start_index == -1) return "-1";
        return s.substr(start_index, min_len);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends