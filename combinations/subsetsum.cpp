#include <iostream>

/* Tina, Compile with g++ */

bool subsetsum(int* set, int size, int sum)
{
    /* Every set contains an empty subset {}, whose sum is 0
       So, Return true, if the required sum is 0 */
    if (sum == 0) {
        // successful termination
        return true;
    }

    /* We can never get a non-zero sum in empty set */
    if (size == 0 && sum != 0)
        return false;

    int head = set[0]; // Head is the first item of the set

    int* tail = &set[1];  // Tail set is Everything except the head
    int tail_size = size - 1;  // Length of Tail is just one shorter

    /*
     * First possibility:
     *  (some_subset_in_tail + head) == sum --> (1)
     *       If head is really a part of the result subset,
     *       then we should be able to find (sum-head) in the tail subset.
     *       because some_subset_in_tail == sum - head // using (1)
     */
    bool including_head = subsetsum(tail, tail_size, sum - head);
    if (including_head) {
        std::cout << head << " ";
        return true;
    }

    /*
     * Second possibility:
     *  some_subset_in_tail == sum  --> (2)
     *  i.e. Check if we can find the sum using the tail subset itself.
     *       head is completely discarded here.
     */
    bool excluding_head = subsetsum(tail, tail_size, sum);
    if (excluding_head) {
        return true;
    }

    return false;
}

int main()
{
    int arr[] = {-2, -1, -2, 5};

    bool result = subsetsum(arr, 3, -3);
    std::cout << std::endl << (result ? "true":"false") << std::endl;

    return 0;
}
