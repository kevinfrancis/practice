#include <iostream>

/**
 * Find missing number in ascending array of integers
 * Assume no duplicates in array
 */
int find_missing(int a[], int len)
{
	int i = 0, j = len-1;

	/* corner case.  Return next greater number if nothing is missing */
	if (a[len-1] == a[0] + len - 1) {
		return a[len-1] + 1;
	}

	while (true) {
		if (j - i < 2) {
			return a[i] + 1;
		}

		int mid_index = (i + j + 1) / 2;
		int expected_mid = a[i] + (mid_index - i);

		if (a[mid_index] != expected_mid) {
			j = mid_index;
		} else {
			i = mid_index;
		}
	}
}

int main()
{
	int a[] = {1,2,4};
	int missing_num = find_missing(a, (sizeof(a)/sizeof(a[0])));

	std::cout << "missing_num = " << missing_num << std::endl;

	return 0;
}
