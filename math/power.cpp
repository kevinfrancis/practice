#include <iostream>

/**
 * Compute x ** y
 * (Recursive version)
 *
 * The maximum stack depth wouldn't exceed 32
 */
double power_recursive(double x, int y)
{
    if (y < 0) {
        return power_recursive(1/x, -y);
    }

    if (y == 0) {
        return 1.0;
    }

    double half_power = power_recursive(x, y/2);
    double result = half_power * half_power;

    /* If y is odd, multiply by x one more time */
    if (y & 1) {
        result *= x;
    }

    return result;
}

/*
 *  x = 2 y = 4
 *  init result = 1
 *  y    x   result = (result * x) if y is odd
 *  4    2    1
 *  2    4    1 
 *  1    16   1 * 16
 *
 *
 *  x = 2, y = 5
 *  init result = 1
 *  y    x   result = (result * x) if y is odd
 *  5    2   1 * 2 = 2
 *  2    4   2
 *  1   16   2 * 16 = 32
 *
 *
 *  x = 2  y = 31
 *  init result = 1
 *  y      x     result = (result * x) if y is odd
 *  31     2       1 * 2 = 2
 *  15     4       2 * 4 = 8
 *   7    16       8 * 16 = 128
 *   3   256     128 * 256 = 32768
 *   1 65536     32768 * 65536 = (2 ** (15 + 16)) // works !
 *
 * Compute x ** y
 * (Non-recursive version)
 */
double power(double x, int y)
{
    if (y < 0) {
        x = 1/x;
        y = -y;
    }

    double result = 1.0;

    for (; y; y >>= 1, x *= x) {
        if (y & 1) {
            result *= x;
        }
    }

    return result;
}


int main(int argc, char* argv[])
{
    double x = std::stod(argv[1]);
    int    y = std::stoi(argv[2]);

    std::cout << "Recursive     => " << power_recursive(x, y) << std::endl;
    std::cout << "Non-recursive => " << power(x, y) << std::endl;

    return 0;
}
