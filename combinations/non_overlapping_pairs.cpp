#include <iostream>
#include <vector>

/*
 * Question from Careercup
 *
 * take an array and print non over lapping in order pairs. example:
 * [1,2,3,4] => input
 *
 * output below is in order combination
 * (1234)
 * (1)(234)
 * (1)(23)(4)
 * (1)(2)(34)
 * (12)(34)
 * (12)(3)(4)
 * (123)(4)
 * (1)(2)(3)(4)
 */

void print_segments(std::vector<int>& v, std::vector<bool>& breaks)
{
    std::cout << "(";
    for (int i = 0; i < v.size(); i++) {
        std::cout << i;
        if (breaks[i] == true) {
            std::cout << ")(";
        }    
    }
    std::cout << ")" << std::endl;
}


/*
 * The core of the solution
 * Keep a break vector "breaks"
 * If breaks[i] is true, a split is needed at v[i]
 */
void print_vec(std::vector<int>& v, std::vector<bool>& breaks, int start_offset)
{
    if (start_offset < breaks.size()) {
        breaks[start_offset] = false;
        print_vec(v, breaks, start_offset + 1);
        breaks[start_offset] = true;
        print_vec(v, breaks, start_offset + 1);
    } else {
        print_segments(v, breaks);
    }
}


void print_non_overlapping_pairs(std::vector<int>& v)
{
    std::vector<bool> breaks(v.size() - 1, false); // breaks used for segmenting
    print_vec(v, breaks, 0);
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    print_non_overlapping_pairs(v);

    return 0;
}
