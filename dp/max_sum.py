#!/usr/bin/env python

import sys


# Only get the sum of the max sub array
def max_sum(a):
    cur_sum = 0
    max_sum = -sys.maxint - 1

    for x in a:
        cur_sum += x
        max_sum = max(max_sum, cur_sum)
        if cur_sum < 0:
            cur_sum = 0

    return max_sum


# Find sub-array with the maximum sum
def max_sub_array(a):

    cur_sum = 0
    max_sum = -sys.maxint - 1

    i = 0
    (max_start, max_end) = (0, 0)

    for j in xrange(len(a)):
        cur_sum += a[j]

        if cur_sum > max_sum:
            (max_start, max_end) = (i, j)
            max_sum = cur_sum

        print('cur_sum=%d max_sum=%d sub_array=%s' %
              (cur_sum, max_sum, str(a[i:j+1])))

        if cur_sum < 0:
            i = j + 1
            cur_sum = 0

    return a[max_start:max_end+1]

#print(max_sub_array([1, -1, 3]))
#print(max_sub_array([9,-2,-5,9]))
print(max_sub_array([4,5,-10,5,6]))
