#!/usr/bin/env python

import sys

def match(pat, s):

    print('match("%s", "%s")' % (pat, s))

    if len(pat) == 0:
        return not(len(s) > 0)

    next_char = pat[1] if len(pat) > 1 else '$'

    if next_char == '*':
        if len(s) == 0 or (pat[0] != s[0] and pat[0] != '.'):
            return match(pat[2:], s)

        if match(pat, s[1:]) or match(pat[2:], s):
            return True

    else:
        if len(s) > 0 and (pat[0] == s[0] or pat[0] == '.'):
            return match(pat[1:], s[1:])

    return False




def main():
    [pat, s] = sys.argv[1:3]
    print(match(pat, s))

if __name__ == '__main__':
    main()

