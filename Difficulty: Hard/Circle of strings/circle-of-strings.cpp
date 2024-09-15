//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        unordered_map<char, int> in_degree;
        unordered_map<char, int> out_degree;
        unordered_map<char, unordered_set<char>> adj_list;
        unordered_set<char> unique_chars;

        // Build the graph
        for (const auto &s : arr) {
            char start = s[0];
            char end = s[s.length() - 1];

            out_degree[start]++;
            in_degree[end]++;
            adj_list[start].insert(end);
            unique_chars.insert(start);
            unique_chars.insert(end);
        }

        // Check in-degree and out-degree balance
        for (char c : unique_chars) {
            if (in_degree[c] != out_degree[c]) {
                return 0; // Not balanced
            }
        }

        // Check strong connectivity using DFS
        unordered_set<char> visited;
        char start_node = arr[0][0]; // Choose any starting node

        stack<char> stack;
        stack.push(start_node);
        while (!stack.empty()) {
            char node = stack.top();
            stack.pop();
            if (visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            for (char neighbor : adj_list[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    stack.push(neighbor);
                }
            }
        }

        // If all unique characters are visited
        if (visited.size() != unique_chars.size()) {
            return 0;
        }

        return 1; // All conditions met
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends