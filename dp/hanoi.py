#!/usr/bin/env python
import sys

# Towers of Hanoi

def move(towers):
    
    # Move n disks from 
    def f(n, a, b, c):
        if n > 1:
            f(n-1, a, c, b)
            f(1,   a, b, c)
            f(n-1, b, a, c)
        elif n == 1:
            v = towers[a].pop()
            towers[c].append(v)
            print('Move %d from tower %d -> %d' % (v, a, c))

    num_disks = len(towers[0])
    assert(num_disks > 0)
    f(num_disks, 0, 1, 2)


def main():
    if len(sys.argv) > 0:
        n = int(sys.argv[1])
    print('Move n=%d disks from tower 0 to 2' % n)
    x = range(n, 0, -1)
    y = []
    z = []
    towers = [x, y, z]
    move(towers)

if __name__ == '__main__':
    main()
