#!/usr/bin/env python

# Given two lists sorted in descending order
# Return a single list by combining both lists and sorting them in descending order


def merge_sorted_lists(lst1, lst2):

    (i, j) = (0, 0)
    result = []

    while i < len(lst1) and j < len(lst2):
        if lst1[i] > lst2[j]:
            result.append(lst1[i])
            i += 1
        elif lst1[i] <= lst2[j]:
            result.append(lst2[j])
            j += 1

    result.extend(lst2[j:] if i == len(lst1) else lst1[i:])
    
    return result


print(merge_sorted_lists([], []))
print(merge_sorted_lists([], [1]))
print(merge_sorted_lists([1], []))
print(merge_sorted_lists([7,5,3], [2,1]))
print(merge_sorted_lists([2,1], [7,5,3]))
print(merge_sorted_lists([7,5,3], [6,5,4,3,2,1]))
