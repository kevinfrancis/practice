#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

//#define DBG

/**
 * Given a vector of heights (of bars), find the capacity of water it can hold
 *
 * @param heights  vector of bar heights
 * @return         Capacity of water that can be held by the bars
 */

int get_holding_capacity(std::vector<int> heights)
{
    std::vector<int>::iterator iter;
    std::stack<int> stk; // Stack of indexes to vector's elements
    int capacity = 0;

    for (iter = heights.begin(); iter != heights.end(); ++iter) {

        int right = iter - heights.begin();
#ifdef DBG
        std::cout << "right = " << right << "; " << std::endl;
#endif

        if (stk.empty() == false) {

            // Pop until we find a height that is greater than heights[right]
            for (int mid = stk.top(); heights[mid] < heights[right]; mid = stk.top()) {
                stk.pop();
#ifdef DBG
                std::cout << "stk.pop(" << mid << ")" << std::endl;
#endif
                if (stk.empty() == false) {
                    int left = stk.top();
                    int min_height = std::min(heights[left], heights[right]);
                    int ydiff = min_height - heights[mid];
                    int xdiff = right - left - 1;
                    capacity += xdiff * ydiff;
#ifdef DBG
                    std::cout << "xdiff, ydiff = " << xdiff << ", " << ydiff << std::endl;
                    std::cout << "capacity = " << capacity << std::endl;
#endif
                } else {
                    break;
                }
            }
        }

        stk.push(right);
#ifdef DBG
        std::cout << "stk.push(" << right << ")" << std::endl;
#endif
    }

    return capacity;
}

int main()
{
    //int arr[] = {16, 5, 3, 2, 1, 4, 7};
    //int arr[] = {16, 14, 13, 4, 6, 8, 4, 6};
    int arr[] = {6, 5, 4, 3, 2, 1, 6, 5, 4, 3, 2, 1, 5};
    //int arr[] = {0,1,2,3,4,5,6,1,2,3,6,1,2,3,6,1,2,3};
    
    std::vector<int> bar_heights (arr,
                                  arr + (sizeof(arr)/sizeof(arr[0])));

    std::cout << get_holding_capacity(bar_heights) << std::endl;

    return 0;
}
