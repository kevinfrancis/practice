#include <iostream>
#include <vector>
#include <sstream>

/**
 * Find the sub-array with the maximum product
 */
int max_product(std::vector<int>& v)
{
    int shorter = 1;
    int longer = 1;
    int max_product = INT_MIN;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            shorter = longer = 1; // reset
            max_product = std::max(max_product, v[i]);
        } else {
            longer *= v[i];

            if (longer > 0) {
                shorter = v[i];
            } else { // longer < 0
                shorter *= v[i];
                if (shorter < 0)
                    shorter = v[i];
            }
            max_product = std::max(max_product,
                                   std::max(shorter, longer));
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
    for (std::string line; std::getline(std::cin, line);) {
        std::stringstream stream(line);
        std::vector<int> v;
        while (not stream.eof()) {
            int x;
            stream >> x;
            v.push_back(x);
        }
        //disp_vector(v);
        std::cout << max_product(v) << std::endl;
    }

#if 0
    //int arr[] = {1, -5, 6, -2, 3};
    //int arr[] = {1, -2, -3, 0, 7, -8, -2};
    //int arr[] = {-1, -9, -45, -34};
    //int arr[] = {-1, -3, -10, 0, 60};
    //int arr[] = {6, -3, -10, 0, 2};
    int arr[] = {6, -3, -10, -10, 2, -1, -1};
    std::vector<int> v(arr, arr + (sizeof(arr)/sizeof(arr[0])));

    disp_vector(v);
    std::cout << "Max product = " << max_product(v) << std::endl;
#endif
    return 0;
}
