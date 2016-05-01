#!/usr/bin/env python
import sys, operator
from math import factorial

# Get all permutations of a string
# with duplicates
# Use each character at first position and attach to the 
# front of each permutation of the rest of the string
# To handle duplicate elements, the same character
# does not occupy the first position more than once.
# Example ( P(x) means perm(x) )
#  P(aba) =>
#    a P(ba)
#      b P(a)
#      a P(b)
#    b P(aa)
#      a P(a)
#      a P(a) # Ignore, because a cannot occupy first again
#    a P(ab)  # Ignore, because a cannot occupy first again
def perm(s):

    if len(s) < 1:
        return [s]

    lst = []
    visited = set([])

    for i in xrange(0, len(s)):
        (head, tail) = (s[i], s[:i] + s[i+1:])
        if head in visited:
            # In each level, same character does not 
            # occupy the first position twice
            continue

        visited.add(head)

        for tail_perm in perm(tail):
            lst.append(head + tail_perm)

    return lst


# Print all permutations of a string (immutable: i.e., without swaps)
def print_perms(s, prefix=''):

    if len(s) == 0:
        print(prefix)

    visited = set([])

    for i in xrange(0, len(s)):
        if s[i] not in visited:
            print_perms(s[:i] + s[i+1:], prefix + s[i])
            visited.add(s[i])


# Print all permutations of a string (Space efficient version)
# Mutable - By Converting to a list first, and
#           swapping instead of creating copies of strings
def print_perms2(s):

    list_of_chars = list(s)

    def swap(l, i, j):
        (l[i], l[j]) = (l[j], l[i])

    def _perm_print(prefix_len):
        if len(list_of_chars) == prefix_len:
            print(''.join(list_of_chars))

        visited = set([])

        for i in xrange(prefix_len, len(list_of_chars)):
            if list_of_chars[i] not in visited:
                visited.add(list_of_chars[i])
                swap(list_of_chars, i, prefix_len)
                _perm_print(prefix_len + 1)
                swap(list_of_chars, i, prefix_len)

    _perm_print(0)


# Naive permutation function (Cannot handle duplicates)
# Use each character at first position
# and append the permutations of all
# the remaining characters
def perm_naive(s):

    if len(s) < 1:
        return [s]

    return [(s[i] + v)
            for i in xrange(0, len(s))
            for v in perm_naive(s[:i] + s[i+1:])]

def test_perms(s, result):
    count_dict = {}
    for c in s:
        try:
            count_dict[c] += 1
        except KeyError:
            count_dict[c] = 1

    denominator = reduce(operator.mul, 
                         [factorial(x) for x in count_dict.values()],
                         1)
    expected_count = factorial(len(s)) / denominator
    print('expected_count=%d' % expected_count)
    unique_count = len(set(result))
    print('unique_count=%d' % unique_count)

    if expected_count == unique_count:
        print('PASS')
    else:
        print('FAIL')


if __name__ == '__main__':
    s = sys.argv[1]
    result = perm(s)
    print('Permutation (%s) = %s' % (s, result))
    test_perms(s, result)
    print_perms2(list(s))
