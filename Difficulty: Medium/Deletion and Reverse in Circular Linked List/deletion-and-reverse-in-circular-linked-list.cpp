//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
   // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head || head->next == head) return head; // Empty or single node case

        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        Node* tail = head;
        
        // Iterate over the list and reverse the links
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        // Fix the circular nature of the list
        tail->next = prev;
        head = prev;

        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if (!head) return nullptr; // If the list is empty

        Node* curr = head;
        Node* prev = nullptr;

        // If head node is the one to be deleted
        if (head->data == key) {
            // If the list contains only one node
            if (head->next == head) {
                delete head;
                return nullptr;
            }
            // Otherwise, find the last node and update head
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Search for the node to be deleted
        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->data != key);

        // If the node to be deleted is found
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
        }

        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends