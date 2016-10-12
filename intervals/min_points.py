#!/usr/bin/env python

from decimal import Decimal

# Given a set of intervals, find the minimum number of points
# which can touch all intervals
def min_points(intervals):

    points_lst = []

    if len(intervals) == 0:
        return points_lst

    sorted_intervals = sorted(intervals)
    finish = sorted_intervals[0][1]  # End of first interval

    for (s, f) in sorted_intervals:
        if s <= finish:
            # Overlaps with previous
            finish = min(finish, f)
        else:
            points_lst.append(finish)
            finish = f

    points_lst.append(finish)

    return points_lst

def test(intervals):
    points_lst = min_points(intervals)
    print('%d points => %s' % (len(points_lst), points_lst))


def main():
    test_cases = [
        [(1,9), (2,12), (10,20), (12,18), (12,16)],
        [(1,10), (11,15), (16,19)],
        [(1,10), (2,14), (11,15), (12,18), (16,19)],
        [(1,10), (2,14), (11,15), (12,18), (13,19)]
    ]

    for test_case in test_cases:
        test(test_case)


if __name__ == '__main__':
    main()

