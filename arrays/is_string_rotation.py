#!/usr/bin/env python

import sys


# Simpler and fast version: O(n) where n is the length of string a
def is_string_rotation(a, b):
    return (len(a) == len(b) and b in (a + a))

# Brute force: O(n*n)  where n is length of string a
def is_string_rotation_brute_force(a, b):
    if len(a) == len(b):
        for i in xrange(len(a)):
            if b == a[i:] + a[:i]:
                return True

    return False

def main():
    [a, b] = sys.argv[1:3]
    print is_string_rotation_brute_force(a, b)

if __name__ == '__main__':
    main()

