#!/usr/bin/env python

# Generic structure that can act as a node in
# a doubly-linked-list as well as a binary tree
class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value


# Convert a binary tree to a sorted doubly linked list
# Return the head of the linked list
#
def tree_to_list(root):
