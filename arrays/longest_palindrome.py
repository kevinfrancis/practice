#!/usr/bin/env python

import sys

def longest_palindrome(s):

    n = len(s)

    # Helper to find longest at i
    # return start index and palindrome
    def longest_at(i):
        (l, r) = (i//2, (i+1)//2)
        if s[l] != s[r]:
            return (l, 0)

        while True:
            (next_l, next_r) = (l-1, r+1)

            if next_l < 0 or next_r >= n or s[next_l] != s[next_r]:
                break

            (l, r) = (next_l, next_r)

        return (l, r-l+1)

    longest_start = -1
    longest_length = 0

    for i in xrange(0, 2*n-1):
        (start, length) = longest_at(i)
        if length > longest_length:
            (longest_start, longest_length) = (start, length)

    return (longest_start, longest_length)

def main():
    s = sys.argv[1]
    (i, length) = longest_palindrome(s)
    print('longest_start=%s, longest_length=%d' % (i, length))
    print('palindrome = %s' % s[i:i+length])

if __name__ == '__main__':
    main()
