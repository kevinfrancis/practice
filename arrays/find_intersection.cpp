#include <iostream>
#include <vector>

/*
 * Find intersection of 2 sorted arrays
 */
std::vector<int> find_intersection(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> result;

    auto it_a = a.begin(); // std::vector<int>::const_iterator it_a
    auto it_b = b.begin();
    
    while (it_a != a.end() and it_b != b.end()) {
        if (*it_a == *it_b) {
            result.push_back(*it_a);
            it_a++;
            it_b++;
        } else if (*it_a < *it_b) {
            it_a++;
        } else { // if (*it_a > *it_b)
            it_b++;
        }
    }

    return result;
}

void print_vector(std::vector<int>& v)
{
    for (int x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> a = {0, 2, 4, 5, 7, 9, 10, 16};
    std::vector<int> b = {3, 4, 5, 8, 12, 16, 17};

    std::vector<int> result(find_intersection(a, b));
    print_vector(result);

    return 0;
}
