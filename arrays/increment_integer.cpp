/* Compile with std=c++11  */
#include <iostream>
#include <vector>

/**
 * Given a vector representation of an integer (arbitrary size)
 * Increment the integer by 1.
 * example: <2,3,4> => <2,3,5>
 *          <9,9,9> => <1,0,0,0>
 */
void increment_integer(std::vector<int>& v)
{
    int carry = 1;

    // The usual sum & carry addition operation
    // auto "it" is of type  "vector<int>::reverse_iterator"
    for (auto it = v.rbegin(); (carry > 0) && it != v.rend(); it++) {
        int sum = *it + carry;
        *it = (sum % 10);
        carry = (sum / 10);
    }

    // All digits are 9.  Increase the vector size by 1
    if (carry > 0) {
        v[0] = 1;
        v.push_back(0);
    }
}

void disp_vector(std::vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> v = {9,9,9,9};
    increment_integer(v);
    disp_vector(v);
    return 0;
}
