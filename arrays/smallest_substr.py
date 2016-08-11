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


# Find smallest substring in s that has all characters from pat 
# in the same order as they appear in pat.
# Characters in pat are all unique (Simpler version)
def smallest_sequential_substr(s, pat):
    if len(s) < len(pat):
        return None

    (smallest_start, smallest_end) = (0, len(s))
    pat_set = set(pat)
    win_start = 0
    expected_pos = 0

    for i in xrange(len(s)):
        if s[i] not in pat_set:
            continue

        if s[i] != pat[expected_pos]:
            expected_pos = 0
            if s[i] != pat[0]:
                # If this is not the first char in pat,
                # start afresh from next character
                continue

        # Start fresh window if expected_pos is 0
        if expected_pos == 0:
            win_start = i

        # Progress to next character in pat
        expected_pos += 1

        # Are we finished with all characters in pat ?
        if expected_pos == len(pat):
            # Then update smallest window
            if i - win_start < smallest_end - smallest_start:
                (smallest_start, smallest_end) = (win_start, i)
            expected_pos = 0

    # If smallest_end never got changed, there was no window we could find.
    # smallest_end would then be equal to len(s) as we initialized it.
    if smallest_end == len(s):
        return None

    return s[smallest_start:smallest_end+1]

def main():
    #print(smallest_substr(sys.argv[1], sys.argv[2]))
    print(smallest_sequential_substr(sys.argv[1], sys.argv[2]))


if __name__ == '__main__':
    main()
