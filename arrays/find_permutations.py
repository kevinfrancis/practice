#!/usr/bin/env python

# Re-write of find_permutations.cpp in Python

import sys
import collections
import copy

def find_perms(s, pat):
    locations = []
    
    if len(pat) > len(s):
        return locations

    char_count = collections.Counter(pat)
    win_char_count = copy.copy(char_count)

    win_start = 0
    
    for i, c in enumerate(s):
        if char_count[c] > 0: # character c in pattern
            win_char_count[c] -= 1
            if win_char_count[c] < 0: # too many occurreces of c inside pat
                # Move win_start until next character equal to c
                while s[win_start] != c:
                    win_char_count[s[win_start]] += 1
                    win_start += 1

            # window length is equal to pattern's length
            if i - win_start + 1 == len(pat):
                if win_char_count[c] == 0:
                    locations.append(win_start)

                # pop win_char_count[c]
                win_char_count[s[win_start]] += 1
                win_start += 1

        else:  # character c not in pattern
            win_char_count = copy.copy(char_count)
            win_start = i + 1

    return locations


def main():
    s = sys.argv[1]
    pat = sys.argv[2]
    for i in find_perms(s, pat):
        print('location: %d, str: %s' % (i, s[i:i+len(pat)]))


if __name__ == '__main__':
    main()
