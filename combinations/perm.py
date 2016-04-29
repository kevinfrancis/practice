#!/usr/bin/env python

# Print all permutations of a string
# Assume no duplicate characters

import sys
from itertools import product


# Pick up character at each position
def perm(s):

    if len(s) <= 1:
        return [s]

    return [(s[i] + v)
            for i in xrange(0, len(s))
            for v in perm(s[:i] + s[i+1:])]
