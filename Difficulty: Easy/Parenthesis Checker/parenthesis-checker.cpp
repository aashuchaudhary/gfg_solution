//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
         stack<char> s;

        // Traverse the given expression
        for (char ch : x) {
            // If an opening bracket is encountered, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            }
            // If a closing bracket is encountered
            else {
                // If the stack is empty, it means no matching opening bracket is available
                if (s.empty()) return false;
                
                char top = s.top();
                s.pop();
                
                // Check if the top of the stack is the corresponding opening bracket
                if ((ch == ')' && top != '(') || 
                    (ch == '}' && top != '{') || 
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If the stack is empty, it means all opening brackets have matching closing brackets
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends