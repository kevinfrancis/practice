#!/usr/bin/env python
import sys
from itertools import izip


# Given a list of co-ordinates of Amazon lockers in a 2-D array (or grid)
# Fill the grid such that each slot has the distance to the nearest locker.
# distance is calculated by traversing horizontal or vertical only.


def getLockerDistanceGrid(num_rows, num_cols, xCoordinates, yCoordinates):

    # Prepare grid
    grid = [[sys.maxint] * num_cols for i in xrange(num_rows)]

    # Switch to 0 based indexing for accessing the grid
    xs = [(x-1) for x in xCoordinates]
    ys = [(y-1) for y in yCoordinates]

    distance = 0

    while len(xs) > 0:

        (new_xs, new_ys) = ([], [])

        # Write distance at grid[x][y] if previous value > distance
        for (x, y) in izip(xs, ys):
            if grid[x][y] > distance:
                grid[x][y] = distance

                # If grid[x][y] is changed, its neighbors may need update
                for i, j in adjacent_positions(num_rows, num_cols, x, y):
                    new_xs.append(i)
                    new_ys.append(j)

        distance += 1
        (xs, ys) = (new_xs, new_ys)

    return grid



def adjacent_positions(num_rows, num_cols, x, y):
    # Pick only horizontal and vertical neighbors
    pairs = [(x, y-1), (x,y+1), (x-1, y), (x+1, y)]

    return [(i, j) for (i, j) in pairs
            if i >= 0 and i < num_rows and
            j >= 0 and j < num_cols]


print(getLockerDistanceGrid(3, 5, [1], [1]))
