#!/usr/bin/env python

def merge_sort(lst):

    workspace = [None] * len(lst)

    # Merge two contiguous segments
    def _merge(start1, len1, start2, len2):
        (i, j, k) = (start1, start2, start1)
        while i < start1 + len1 and j < start2 + len2:
            if lst[i] <= lst[j]:
                workspace[k] = lst[i]
                i += 1
            else:
                workspace[k] = lst[j]
                j += 1
            k += 1

        # Write remaining items to workspace
        remaining_range = xrange(j, start2+len2) if (i == start1 + len1) \
                          else xrange(i, start1+len1)
        for i in remaining_range:
            workspace[k] = lst[i]
            k += 1

        # Copy back from workspace to original list
        for i in range(start1, start2 + len2):
            lst[i] = workspace[i]

    # Core of the merge sort algorithm
    def _msort(start, length):
        if length >= 2:
            half_len = length // 2
            _msort(start, half_len)
            _msort(start + half_len, length - half_len)
            _merge(start, half_len, start + half_len, length - half_len)

    _msort(0, len(lst))

lst = [5,6,7,8,1,2,3]
merge_sort(lst)
print(lst)
