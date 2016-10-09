#!/usr/bin/env python

from decimal import Decimal
import heapq

INFINITY = Decimal('Infinity')

# Dijkstra's shortest path algorithm
def dijkstra(g, s, f):
    dist = {}
    prev = {}

    # distance to all vertices from s
    for v in g.vertices:
        dist[v] = INFINITY
        prev[v] = None

    # Set start distance as 0
    dist[s] = 0

    # Create a min-heap based on dist to each vertex
    q = [(dist[v], v) for v in dist]
    heapq.heapify(q)

    while len(q):
        (dist_v, v) = heapq.heappop(q)
        
        for v_adj, cost in g.vertices[v].iteritems():
            if dist_v + cost < dist[v_adj]:
                dist[v_adj] = dist_v + cost
                prev[v_adj] = v
                print('updating distance of v_adj %s  dist=%d' % (v_adj, dist[v_adj]))

                # update distance in priority queue ( The below is very inefficient implementation)
                for i, pair in enumerate(q):
                    if pair[1] == v_adj:
                        q[i] = (dist[v_adj], v_adj)
                heapq.heapify(q)

    print(dist)
        

class UndirectedGraph:
    def __init__(self):
        self.vertices = {}

    def add_edge(self, a, b, cost):
        if a != b:
            if a not in self.vertices:
                self.vertices[a] = {}
            if b not in self.vertices:
                self.vertices[b] = {}
            self.vertices[a][b] = cost
            self.vertices[b][a] = cost

    def __str__(self):
        return '\n'.join('%s: %s' % (v, adj)
                         for v, adj in self.vertices.iteritems())

def main():
    g = UndirectedGraph()
    g.add_edge('a', 'b', 8)
    g.add_edge('b', 'c', 5)
    g.add_edge('a', 'd', 1)
    g.add_edge('b', 'd', 2)
    g.add_edge('c', 'd', 9)
    print(g)

    dijkstra(g, 'a', 'c')

if __name__ == '__main__':
    main()

