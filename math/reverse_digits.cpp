#include <iostream>

/*
 * Reverse the digits in an integer
 *
 * (e.g. reverse_digits(543) => 345
 *       reverse_digits(-345) => -543)
 *
 *   x = 543
 *
 *   x   LSD   result
 *  543   3    3
 *   54   4    34
 *    5   5    345
 */
int reverse_digits(int x)
{
    int result = 0;

    for (; x; x /= 10) {
        result = (10 * result) + (x % 10);
    }

    return result;
}

int main(int argc, char* argv[])
{
    std::cout << reverse_digits(std::stoi(argv[1])) << std::endl;
    return 0;
}
