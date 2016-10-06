#!/usr/bin/env python


# Detect if a directed graph has cycles

test_graph = {
    'A': ['B', 'C'],
    'B': ['C', 'D'],
    'C': ['D'],
    'D': ['E'],
    'E': ['F'],
    'F': ['C']
}


# Colors for tracking visited state
WHITE = 0
GRAY = 1
BLACK = 2

# Check if a directed graph has cycles
def has_cycles_dg(graph):

    # Track visited state of each node by color
    # (WHITE: Never visited, GRAY: being explored, BLACK: Finished)
    visited_state = dict([(v, WHITE) for v in graph])

    # inner function - DFS slightly adjusted
    def _dfs(v):
        if visited_state[v] == BLACK:
            # Black means that we have already found that this node isn't part of cycle
            return False

        if visited_state[v] == GRAY:
            # We explored from a GRAY node, and met the same GRAY node.
            # Therefore v is in a cycle
            print('detected cycle at %s' % v)
            return True

        # Mark GRAY to indicate that this node is being explored
        visited_state[v] = GRAY

        # Explore all adjacent vertices
        for v_adj in graph[v]:
            if _dfs(v_adj):
                return True

        # After all adjacent vertices are explored, mark as BLACK
        visited_state[v] = BLACK
        return False

    for v in graph:
        if _dfs(v):
            return True

    return False

undirected_graph = {
    'A': ['B', 'E'],
    'B': ['A', 'C', 'F'],
    'C': ['B', 'D', 'F'],
    'D': ['C'],
    'E': ['A'],
    'F': ['C', 'B']
}


# Check if undirected graph has cycles
def has_cycles_ug(graph):
    # Track visited state of each node by color
    visited_state = dict([(v, WHITE) for v in graph])

    def _dfs(v_prev, v):
        if visited_state[v] == BLACK:
            return False

        if visited_state[v] == GRAY:
            print('cycle detected at vertex v=%s v_prev=%s' % (v, v_prev))
            return True

        visited_state[v] = GRAY

        # Explore all adj vertices
        for v_adj in graph[v]:
            if v_adj != v_prev and _dfs(v, v_adj):
                return True

        visited_state[v] = BLACK
        return False


    for v in graph:
        if _dfs(None, v):
            return True

    return False





 
def main():
    print('directed graph test:')
    print(has_cycles_dg(test_graph))

    print('undirected graph test:')
    print(has_cycles_ug(undirected_graph))

if __name__ == '__main__':
    main()
