#include <iostream>
#include <vector>

/**
 * Find the sub-array with the maximum product
 */
int max_product(std::vector<int>& v)
{
	int shorter = 1;
	int longer = 1;
	int max_product = INT_MIN;

	for (int i = 0; i < v.size(); i++) {
		if (longer * v[i] > 0) {
			shorter = v[i];
			longer *= v[i];
			max_product = std::max(max_product,
								   std::max(shorter, longer));
		} else if (longer * v[i] < 0) {
			if ((shorter * v[i]) < 0) {
				shorter = v[i];
			} else {
				shorter *= v[i];
			}
			longer *= v[i];
			max_product = std::max(max_product,
								   std::max(shorter, longer));
		} else { // v[i] == 0
			shorter = longer = 1; // reset
			max_product = std::max(max_product, v[i]);
		}
	}

	return max_product;
}

void disp_vector(std::vector<int>& v)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main()
{
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
	//int arr[] = {-1, -9, -45, -34};
	//int arr[] = {-1, -3, -10, 0, 60};
	//int arr[] = {6, -3, -10, 0, 2};
	//int arr[] = {6, -3, -10, -10, 2, -1, -1};
	std::vector<int> v(arr, arr + (sizeof(arr)/sizeof(arr[0])));

	disp_vector(v);
	std::cout << "Max product = " << max_product(v) << std::endl;

	return 0;
}
