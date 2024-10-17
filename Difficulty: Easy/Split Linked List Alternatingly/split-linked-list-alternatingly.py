#User function Template for python3
'''
class Node:
    def _init_(self, data):
        self.data = data
        self.next = None

'''

# Definition for singly-linked list node.
class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class Solution:
    def alternatingSplitList(self, head):
        # Initialize dummy nodes for two lists
        a_dummy = ListNode(0)
        b_dummy = ListNode(0)
        
        # Two pointers to track the current end of two lists
        a_curr = a_dummy
        b_curr = b_dummy
        
        # Pointer to traverse the original list
        curr = head
        index = 0
        
        # Traverse the list
        while curr:
            if index % 2 == 0:
                # Add to list 'a'
                a_curr.next = curr
                a_curr = a_curr.next
            else:
                # Add to list 'b'
                b_curr.next = curr
                b_curr = b_curr.next
            
            # Move to the next node and increment index
            curr = curr.next
            index += 1
        
        # End both lists
        a_curr.next = None
        b_curr.next = None
        
        # Return the heads of both lists
        return [a_dummy.next, b_dummy.next]

# Utility function to create a linked list from a list
def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    curr = head
    for value in arr[1:]:
        curr.next = ListNode(value)
        curr = curr.next
    return head

# Utility function to print a linked list
def print_linked_list(head):
    curr = head
    res = []
    while curr:
        res.append(str(curr.data))
        curr = curr.next
    print("->".join(res) if res else "<empty linked list>")

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()


if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        head = Node(arr[0])
        tail = head

        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next

        ob = Solution()
        result = ob.alternatingSplitList(head)
        printList(result[0])
        printList(result[1])

# } Driver Code Ends