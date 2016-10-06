#!/usr/bin/env python

# Generic structure that can act as a node in
# a doubly-linked-list as well as a binary tree
class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value


# Convert a binary search tree to a sorted doubly linked list
# Return the head of the linked list (or None if root is None)
def tree_to_list(tree_root):

    # Converts tree with root "n" to a linked list
    # And returns (first, last) pair of the linked list. Or (None, None) if head is None
    def _to_list(root):

        if root is None:
            return (None, None)

        (left_first, left_last) = _to_list(root.left)
        (right_first, right_last) = _to_list(root.right)

        first = last = root

        if left_last:
            left_last.right = root
            root.left = left_last
            first = left_first

        if right_first:
            right_first.left = root
            root.right = right_first
            last = right_last

        return (first, last)

    (first, last) = _to_list(tree_root)
    return first


def main():
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)

    n3.left = n1
    n1.right = n2

    n3.right = n5
    n5.left = n4
    n5.right = n6

    list_head = tree_to_list(n3)

    # printing list
    node = list_head
    while node is not None:
        print(node.value)
        node = node.right

if __name__ == '__main__':
    main()
