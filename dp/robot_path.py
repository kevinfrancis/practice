#!/usr/bin/env python

import sys

# From Cracking the Coding interview
# Given
#  maze  r rows & c cols.  maze[i][j] = { 0, if cell is traversable, 
#                                         1, if it is an obstacle }
#  robot standing at 0th row, 0th col.
#  robot can only move right or down 
# (i.e. next step from (i,j) can be (i+1, j) or (i, j+1) within the bounds of the maze
#
# Find a path from [0][0] to [r-1][c-1]
#


def find_path(maze):

    path = []
    r = len(maze)    # num_rows
    c = len(maze[0]) # num_cols
    start_cell = (0, 0)
    visited_set = set([])

    # Core func (DFS)
    def _find_path_from(end_cell):
        (i, j) = end_cell
        if i < 0 or j < 0 or maze[i][j] == 1 or (i,j) in visited_set: # not traversable
            return False

        print('visiting cell %s' % str(end_cell))
        visited_set.add((i,j))

        if start_cell == end_cell: # destination cell
            return True

        for prev_cell in [(i, j-1), (i-1, j)]: # find path from top & left adj cells
            if _find_path_from(prev_cell):
                path.append(prev_cell)
                return True

        return False

    # Call inner func that finds path using DFS
    if _find_path_from((r-1, c-1)) == True:
        path.append((r-1, c-1))
        return path

    return path

def main():
    maze = [[0, 0, 0, 0],
            [1, 1, 1, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 0]]
    path = find_path(maze)
    if path is None:
        print('No path found')
        sys.exit(0)
    print(path)

    # Mark cells in path as 2 for easy viewing
    for (i,j) in path:
        maze[i][j] = 2

    for row in maze:
        print(row)

if __name__ == '__main__':
    main()

