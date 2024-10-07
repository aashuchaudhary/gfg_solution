//{ Driver Code Starts
#include <stdint.h>

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *npx;

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b) {
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data);

vector<int> getList(struct Node *head);

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        struct Node *head = NULL;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            head = insert(head, number);
        }

        vector<int> vec = getList(head);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        for (int i = vec.size() - 1; i >= 0; i--) {
            cout << vec[i] << " ";
        }
        cout << "\n";
    }
    return (0);
}

// } Driver Code Ends


/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/
// Function to insert data at the front of the list
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    // Case 1: Empty Linked List
    newNode->npx = head;

    // Case 2: Non-empty Linked List (Update npx of the head)
    if (head) {
        head->npx = XOR(newNode, head->npx);
    }
    return newNode;
}

// Function to retrieve the list as a vector
vector<int> getList(Node* head) {
    vector<int> ans;
    Node *curr = head, *prev = NULL, *next;

    // Traverse the list
    while (curr) {
        ans.push_back(curr->data);

        // Compute the next node
        next = XOR(prev, curr->npx);

        // Update prev and curr for the next iteration
        prev = curr;
        curr = next;
    }
  return ans;
}
