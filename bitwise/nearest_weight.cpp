#include <iostream>
#include <string>

/* Find the nearest integer with the same number of 1 bits.
   The following 2 inputs are invalid, and need not be handled:
      All bits 0
      All bits 1
*/

unsigned long nearest_weight(unsigned long x)
{
    bool flip = (x & 1) ? true : false;

    if (flip) {
        x = ~x;
    }

    /* Set all bits to the right of the least-significant 1 bit
       and clear all bits to the left of it */
    unsigned long mask = x ^ (x-1);

    /* In mask, clear all bits except the two highest
       significant 1 bits */
    mask ^= (mask >> 2);

    /* In x, flip the least significant 1 bit
       and the 0 bit to its right */
    x ^= mask;
    
    if (flip) {
        x = ~x;
    }

    return x;
}


int main(int argc, char* argv[])
{
    std::cout << nearest_weight(std::stol(argv[1])) << std::endl;

    return 0;
}
