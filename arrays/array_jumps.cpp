#include <iostream>
#include <vector>
#include <utility>
#include <stack>

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


/**
 * Variant: Find the minimum number of jumps required
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int min_jumps(std::vector<int>& v)
{
    std::stack<int> stk;  // stack of indexes
    stk.push(v.size() - 1);

    for (int i = v.size() - 2; i >= 0; i--) {
        int last_popped = -1;
        while (!stk.empty() and 
               (i + v[i] >= stk.top())) {
            last_popped = stk.top();
            stk.pop();
        }
        if (last_popped != -1)
            stk.push(last_popped);

        if (i + v[i] >= stk.top())
            stk.push(i);
    }

    if (stk.top() == 0)
        return stk.size() - 1;

    return -1;
}

int main()
{
    std::vector<int> v = {2, 1, 2, 1, 2, 1, 1};
    std::cout << "jump possible = " << jump_test(v) << std::endl;
    std::cout << "min jumps     = " << min_jumps(v) << std::endl;
    return 0;
}
