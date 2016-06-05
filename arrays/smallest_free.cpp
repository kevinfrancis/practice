#include <iostream>
#include <vector>

/*
 * Given an array that contains both positive and negative integers
 * Find the smallest positive integer missing in the array
 * You are allowed to modify v.
 * Time complexity: O(n)
 * Additional Space: O(1)
 * In my opinion, the actual space complexity is still O(n)
 * since I am using the array as hash.
 */

/*
 * Example (after partitioning)
 *
 *  3 1 0 4
 *  3 1 0 -4
 *  3 -1 0 -4
 *  -3 -1 0 -4
 *
 * First non-zero item is at index 2.
 * Therefore 2 is the smallest missing
 */

int get_smallest_free(std::vector<int>& v)
{
    int i, j, k;

    // Partition v (<=0 to left, and >0 to right)
    // Invariant: v[k] <= 0 for all k < j
    for (i = 0, j = 0; i < v.size(); i++) {
        if (v[i] <= 0) {
            std::swap(v[i], v[j++]);
        }
    }

    // j points to the start of positive values
    // for each item v[k], negate the index at value v[k]
    for (k = j; k < v.size(); k++) {
        int key = j + std::abs(v[k]) - 1; // since v[k] could have been negated already
        if (key < v.size() and v[key] > 0) {
            v[key] = -v[key]; // negate only if positive
        }
    }

    // now search for the smallest missing
    for (k = 0; j + k < v.size() and v[j + k] < 0; k++)
        ;

    return k + 1;
}


int main()
{
    std::vector<int> v = { 2, 3, 7, 6, 8, -1, -10, 15 };
    //std::vector<int> v = {1, 1, 0, -1, -2};
    //std::vector<int> v = {2, 3, -7, 6, 8, 1, -10, 15};
    //std::vector<int> v = {1,3,4,2};
    std::cout << get_smallest_free(v) << std::endl;
    return 0;
}
