#!/usr/bin/env python

import sys

# Return powerset of the given set s
def powerset(s):
    lst = [x for x in s] # convert to list first.  Greatly simplifies the problem
    subsets = []

    # @param i      index in lst
    # @param items  to store items belonging to the current subset
    def f(i, items):
        if i == len(lst):
            subsets.append(set(items))
        else:
            items.append(lst[i])
            f(i+1, items)        # items without lst[i]
            items.pop()
            f(i+1, items) 

    f(0, [])
    return subsets


def main():
    lst = range(1, 1 + int(sys.argv[1]))
    s = set(lst)
    subsets = powerset(s)
    print('count = %d' % len(subsets))
    print(subsets)


if __name__ == '__main__':
    main()

