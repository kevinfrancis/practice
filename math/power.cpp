#include <iostream>

/**
 * Compute x ** y
 */
double power(double x, uint32_t y)
{
    if (y == 0) {
        return 1.0;
    }

    double half_power = power(x, y/2);
    double result = half_power * half_power;

    /* If y is odd, multiply by x one more time */
    if (y & 1) {
        result *= x;
    }

    return result;
}


int main(int argc, char* argv[])
{
    double x = std::stod(argv[1]);
    double y = std::stod(argv[2]);

    std::cout << power(x, y) << std::endl;

    return 0;
}
