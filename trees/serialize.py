#!/usr/bin/env python

# Serialize & de-serialize a binary tree of integers (can have duplicates)

# Serialize Binary Tree
# e.g.
#   1
#  / \
# 2   3
#
# will be serialized as
# (1(2()())(3()()))
#
def serialize(node):

    if node is None:
        return '()'

    return '(' + str(node.value) + serialize(node.left) + serialize(node.right) + ')'


# Deserialize - convert string back to binary tree
def deserialize(s):

    # return either Node(value) or None, and length of string used for parsing
    def _parse_value(i):
        assert(s[i] == '(')

        end = s.find('(', i+1)
        value = int(s[i+1:end])
        return (Node(value), end)

    # Starting from '(', parse until ')'
    def _parse_sub_tree(i):
        if s[i+1] == ')':
            (node, end_pos) = (None, i+1)
        else:
            (node, end_pos) = _parse_value(i)
            (node.left, end_pos) = _parse_sub_tree(end_pos)
            (node.right, end_pos) = _parse_sub_tree(end_pos)

        # s[end_pos] must be right-paren ')'.  Therefore we return end_pos+1
        return (node, end_pos+1)

    (root, end_pos) = _parse_sub_tree(0)
    return root

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

def main():
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)

    n1.left = n2
    n1.right = n3

    n2.left = Node(4)
    n3.right = Node(5)

    s = serialize(n1)
    print('serialized = ' + s)

    d = deserialize(s)
    assert(s == serialize(d))
    print('deserialization verified!')


if __name__ == '__main__':
    main()
