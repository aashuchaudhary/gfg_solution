# your task is to complete this function
# Function should return an integer value
# head1 denotes head node of 1st list
# head2 denotes head node of 2nd list

'''
class node:
    def __init__(self):
        self.data = None
        self.next = None
'''

# Definition for singly-linked list node.
class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class Solution:
    def multiply_two_lists(self, l1: Node, l2: Node) -> int:
        MOD = 10**9 + 7
        
        # Construct the first number from the linked list
        num1 = 0
        while l1:
            num1 = (num1 * 10 + l1.data) % MOD  # Change 'val' to 'data'
            l1 = l1.next
        
        # Construct the second number from the linked list
        num2 = 0
        while l2:
            num2 = (num2 * 10 + l2.data) % MOD  # Change 'val' to 'data'
            l2 = l2.next
        
        # Return the product modulo 10^9 + 7
        return (num1 * num2) % MOD

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def new_node(data):
    return Node(data)


def push(head_ref, new_data):
    new_Node = new_node(new_data)
    new_Node.next = head_ref[0]
    head_ref[0] = new_Node


def reverse(r):
    prev = None
    cur = r[0]
    while cur is not None:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    r[0] = prev


def free_list(Node):
    while Node:
        temp = Node
        Node = Node.next
        del temp


def print_list(Node):
    while Node:
        print(Node.data, end=" ")
        Node = Node.next
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        first, second = [None], [None]
        arr = list(map(int, input().split()))
        for num in arr:
            push(first, num)

        brr = list(map(int, input().split()))
        for num in brr:
            push(second, num)

        reverse(first)
        reverse(second)

        ob = Solution()
        res = ob.multiply_two_lists(first[0], second[0])
        print(res)

# } Driver Code Ends