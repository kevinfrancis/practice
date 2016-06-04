#include <iostream>
#include <forward_list>


void print_list(std::forward_list<int> &l)
{
    for (int& i : l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool is_zero(std::forward_list<int> &l)
{
    auto it = l.begin();
    return (*it == 0 && ++it == l.end());
}


/**
 * Find the product of two integers stored in list
 * The digits in the integers are reversed in the list representation.
 * e.g. Number 234 is stored as List [ 4 -> 3 -> 2 ]
 */
std::forward_list<int> *
find_product(std::forward_list<int>& x, std::forward_list<int>& y)
{
    std::forward_list<int> *z_ptr = new std::forward_list<int>;
    std::forward_list<int> &z = *z_ptr;

    // start with a zero at beginning
    z.insert_after(z.before_begin(), 0);

    // return early if one of the items is 0
    if (is_zero(x) or is_zero(y)) {
        return z_ptr;
    }

    auto z_start = z.begin();
    auto z_it = z_start;
    auto z_prev_last = z.before_begin(); // to hold previous to last item

    // List z is extended on demand

    for (int& _x : x) {
        z_it = z_start;
        for (int& _y: y) {
            // If this is last digit in z, insert 0 at the end
            auto z_next = z_it;
            z_next++;
            if (z_next == z.end()) {
                z_next = z.insert_after(z_it, 0);
            }
            int v = (*z_it + (_x * _y));
            *z_it = v % 10;     // product
            *z_next += v / 10;  // carry
            z_prev_last = z_it; // backup previous to last
            z_it++;             // next digit in z
        }
        z_start++;  // next digit to start from in z
    }

    if (*z_it == 0) {
        z.erase_after(z_prev_last);
    }

    return z_ptr;
}


int main(int argc, char* argv[])
{
    std::forward_list<int> x = {4,5,3,9,2,5};
    std::forward_list<int> y = {3,9,9,9,8,7,6,3,9,8};

    print_list(x);
    print_list(y);
    std::forward_list<int> *z = find_product(x, y);
    print_list(*z);
}
