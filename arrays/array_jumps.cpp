#include <iostream>
#include <vector>

/**
 * Given a vector v where
 *    v[i] contains the number of positions we 
 *    can jump towards the end
 * Find if it is possible to jump to the last index from the v[0]
 */
bool jump_test(std::vector<int>& v)
{
    int last_pos = v.size() - 1;

    // Traverse backwards from the 2nd last element
    for (int i = v.size() - 2; i >= 0; i--) {
        // if last_pos is reachable from i, update last_pos
        if (i + v[i] >= last_pos) {
            last_pos = i;
        }
    }

    return (last_pos == 0);
}

int main()
{
    std::vector<int> v = {5, 0, 0, 0, 0, 0};
    std::cout << jump_test(v) << std::endl;
    return 0;
}
