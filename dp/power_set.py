#!/usr/bin/env python

import sys

# Return powerset of the given set s
def powerset(s):
    lst = [x for x in s]
    subsets = []
    
    def f(i, items):
        if i == len(lst):
            subsets.append(set(items))
        else:
            f(i+1, items)        # items without lst[i]
            items.append(lst[i]) # items with lst[i]
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

