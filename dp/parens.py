#!/usr/bin/env python

import sys


# Generate all well-formed expressions with n parentheses
def get_paren_exps(n):

    s = [''] * 2 * n
    exp_lst = []

    # i : write-index in s
    # l : number of left-paren characters '(' so far
    # r : number of right-paren characters ')' so far
    def f(i, l, r):

        if i == 2 * n: # reached end
            exp_lst.append(''.join(s))
            return

        if l < n:
            s[i] = '('
            f(i+1, l+1, r)
            s[i] = ''

        if r < l:
            s[i] = ')'
            f(i+1, l, r+1)
            s[i] = ''

    f(0, 0, 0)
    return exp_lst


# Test function
def check_paren_balance(exp):
    x = 0

    for c in exp:
        if c == '(':
            x += 1
        if c == ')':
            x -= 1
            if x < 0:
                print('balance failed: %s' % exp)
                assert(False)

    if x != 0:
        print('balance failed at end: %s' % exp)
        assert(False)
        


def main():
    n = int(sys.argv[1])
    exps = get_paren_exps(n)
    unique_exps = set(exps)  # for verifying

    print('count  = %d' % len(exps))
    print('unique = %d' % len(unique_exps))
    print(exps)


    for exp in exps:
        check_paren_balance(exp)
    print('Paren balance verified.  All expressions are well formed')


if __name__ == '__main__':
    main()
