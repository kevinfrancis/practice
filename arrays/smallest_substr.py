#!/usr/bin/env python

import sys
import collections
import copy

# Find the smallest substring of a that contains all characters in b
# Repeated characters in b must also be accounted for. i.e.,
#   If a character c has a count of k in string b,
#     then c must occur at least k times in the substring of a
def smallest_substr(a, b):

    # b cannot fit inside a
    if len(b) > len(a):
        return None

    pending_count = collections.Counter(b) # Count of chars yet to be seen in window
    pending_set = set(b)  # Set of chars yet to be seen in window

    j = 0
    (smallest_start, smallest_end) = (0, len(a))

    for i in xrange(len(a)):
        if a[i] not in pending_count:
            continue

        # Move j until a[i:j] contains all characters in b
        while j < len(a) and len(pending_set) > 0:
            if a[j] in pending_count:
                pending_count[a[j]] -= 1
                if pending_count[a[j]] == 0:
                    pending_set.remove(a[j])
            j += 1

        # update smallest window
        if j - i < smallest_end - smallest_start + 1 and len(pending_set) == 0:
            (smallest_start, smallest_end) = (i, j-1)

        pending_count[a[i]] += 1 # Finally, exclude character for upcoming window
        if pending_count[a[i]] > 0:
            pending_set.update(a[i])

    if smallest_end == len(a):
        return None

    return a[smallest_start:smallest_end+1]


def main():
    print(smallest_substr(sys.argv[1], sys.argv[2]))


if __name__ == '__main__':
    main()
