#include <iostream>

/**
 * Check if the digits in an integer form a palindrome
 *
 *  Keep constructing reverse until reverse >= x
 *
 *  (Odd length digits)
 *   x = 345
 *
 *   x   LSD   reversed  reversed >= x ?
 * 343   3     3         false
 *  34   4     34        true   
 *
 *  (Even length digits)
 *  x = 4224
 *   x       LSD     reversed    reversed >= x  x /= 10
 * 4224        4       4          false          422
 * 422         2       42         false          42
 * 42    (FINISH)
 */
bool is_palindrome(int x)
{
    int reversed = 0;

    x = std::abs(x);

    while (reversed < x) {
        reversed = (10 * reversed) + (x % 10);
        if (reversed >= x)  // Needed for even-length case
            break;
        x /= 10;
    }

    return (reversed == x);
}

int main(int argc, char* argv[])
{
    std::cout << is_palindrome(std::stoi(argv[1])) << std::endl;
    return 0;
}
