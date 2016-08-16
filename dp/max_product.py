#!/usr/bin/env python

'''
-1  0
 x   max_p   min_p   result
-1    -1      -1      -1
 0     0       0       0


-5 -6 0 5 7 -2
 x   max_p   min_p   result
-5     -5      -5      -5
-6     -5      -5
       30      -6      30
 0      0       0      30  # 0 resets
 5      5       0      30 
 7     35       0      35
-2      0      35
        0     -70      35
-1    -70       0
       70      -1      70



5 7 0 -5 -9
 x   max_p   min_p   result
 5    5        5       5
 7    35       7      35
 0    0        0      35
-5    0        0
      0       -5      35
-9   -5        0
     45       -9      45


-2 -2 -2 -2 -2 -2
 x   max_p   min_p   result
-2    -2      -2       -2
-2    -2      -2            # swap max_p, min_p
       4      -2        4
-2    -2       4            # swap max_p, min_p
       4      -8        4
-2    -8       4
       16     -8       16
-2    -8      16
       16    -32       16
-2    -32     16
       64    -32       64
      
'''

def max_product(a):
    result = a[0]
    (max_p, min_p) = (a[0], a[0])

    for x in a[1:]:
        if x < 0:
            (max_p, min_p) = (min_p, max_p)

        max_p = max(x, max_p * x)
        min_p = min(x, min_p * x)
        result = max(result, max_p)

    return result


print(max_product([-1, 0]))
print(max_product([-5,-6, 0, 5, 7]))
print(max_product([5, 7, 0, -5, -9]))
print(max_product([0, -1, 0, -2]))
print(max_product([-2, -2, -2, -2, -2, -2]))
