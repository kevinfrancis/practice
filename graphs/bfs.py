#!/usr/bin/env python

import Queue

test_graph = {
    'A': ['B', 'C'],
    'B': ['C', 'D'],
    'C': ['D'],
    'D': ['E'],
    'E': ['F'],
    'F': ['A']
}

'''
A ---> B----->  D ----> E
\      |        ^
 \     |        |
  \    v        |
    -> C--------+
'''

#
# Update visited whenever a node is inserted into queue
def bfs_traverse(graph, start_node):

    # Data structures needed for traversal
    visited_set = set([])
    q = Queue.Queue()

    # Helper function to add a node in queue, and to visited set
    def _update(node):
        if node not in visited_set:
            q.put(node)
            visited_set.update(node)

    # Add first node to queue
    _update(start_node)

    # For each node in queue, do _update for the child node
    while not q.empty():
        node = q.get()

        for child in graph[node]:
            _update(child)

    return visited_set

'''
q         visited_set
A         A
B C       A B C
C D       A B C D
D         A B C D
E         A B C D E
'''

print(bfs_traverse(test_graph, 'A'))
