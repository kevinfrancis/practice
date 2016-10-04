#!/usr/bin/env python

import sys
import Queue

# From "Cracking the Coding Interview"
# Given n steps, and that the possible jumps are {1,2,3}
# Find the number ways the n steps can be climbed
# Non-recursive version below
def fcount(n):
    if n <= 0:
        return 0

    _cache = [1, 2, 4]

    if n <= 3:
        return _cache[n-1]

    result = 0

    for i in xrange(0, n-3):
        result = sum(_cache)
        _cache[0] = _cache[1]
        _cache[1] = _cache[2]
        _cache[2] = result

    return result

# recursive version (with memoization)
def rcount(nsteps, max_jmp=3):
    _cache = [0] * nsteps

    def _f(n):
        if n == 0:
            return 1
        
        count = 0
        
        for i in xrange(1, min(n, max_jmp)+1): # i in {1, 2, ..., max_jmp}
            if _cache[n-i] == 0:
                _cache[n-i] = _f(n-i)
                print('_cache[%d] = %d' % (n-i, _cache[n-i]))
            count += _cache[n-i]

        return count

    return _f(nsteps)

def main():
    nsteps = int(sys.argv[1])
    print(rcount(nsteps))

if __name__ == '__main__':
    main()
