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
	int max_reach = 0;

	for (int i = 0; i < v.size() - 1 and i <= max_reach; i++) {
		max_reach = std::max(max_reach, i + v[i]);
		if (max_reach >= v.size() - 1) {
			break;
		}
	}

	return (max_reach >= v.size() - 1);
}


/**
 * Variant: Find the minimum number of jumps required
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int min_jumps(std::vector<int>& v)
{
	int max_reach = 0;
	int min_jumps = 0;

	for (int i = 0; i < v.size() - 1 and i <= max_reach; i++) {
		if (max_reach < i + v[i]) {
			max_reach = i + v[i];
			min_jumps++;
		}
		if (max_reach >= v.size() - 1) {
			break;
		}
	}

	return (max_reach >= v.size() - 1) ? min_jumps : -1;
}

int main()
{
    std::vector<int> v = {3, 1, 2, 0, 1};
    std::cout << "jump possible = " << jump_test(v) << std::endl;
    std::cout << "min jumps     = " << min_jumps(v) << std::endl;
    return 0;
}
