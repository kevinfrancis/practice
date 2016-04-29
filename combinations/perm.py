#!/usr/bin/env python
import sys, operator
from math import factorial

# Print all permutations of a string
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
