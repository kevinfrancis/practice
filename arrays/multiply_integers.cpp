#include <iostream>
#include <vector>

void disp_vector(std::vector<int>& v)
{
    std::cout << "[ ";
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it <<  " ";
    }
    std::cout << "]" << std::endl;
}


/**
 * Find product of two integers represented as vectors
 */
std::vector<int>* product(std::vector<int>& x, std::vector<int>& y)
{
    std::vector<int>* v_ptr = new std::vector<int>(x.size() + y.size(), 0);
    std::vector<int>& v = *v_ptr;
    
    for (auto x_it = x.rbegin(); x_it != x.rend(); x_it++) {
        int i = v.size() - 1 - (x_it - x.rbegin());

        for (auto y_it = y.rbegin(); y_it != y.rend(); y_it++, i--) {
            int p = v[i] + (*x_it) * (*y_it);

            v[i] = p % 10;
            v[i-1] += p / 10;
        }
    }

    // Erase 0s from beginning
    while (*v.begin()  == 0) {
        v.erase(v.begin());
    }

    return v_ptr;
}

int main(int argc, char* argv[])
{
    std::vector<int> x = {2, 3, 4, 9};
    std::vector<int> y = {9, 9, 8, 1, 6, 7, 8, 9, 5, 9, 9, 9};

    std::cout << "      x = ";
    disp_vector(x);

    std::cout << "      y = ";
    disp_vector(y);
    
    std::vector<int>* v_ptr = product(x, y);
    std::cout << "(x * y) = ";
    disp_vector(*v_ptr);

    return 0;
}
