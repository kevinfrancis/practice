#!/usr/bin/env python

def num_interpretations(s, d):

    if len(s) == 0:
        return 0

    count = 0

    for i in xrange(0, len(s)):
        head = s[:i]
        tail = s[i+1:]

        if head not in d:
            break

        if len(tail) == 0:
            count += 1
        else:
            count += num_interpretations(tail)

    return count
