#include <iostream>

/*
  Example:
     10 X 1011
  ----------
     10
    10
   00
  10
----------
  10110
----------
*/

uint32_t multiply(uint32_t x, uint32_t y)
{
    uint32_t result = 0;
    
    for (; y; y >>= 1) {
        if (y & 1) {
            result += x;
        }
        x <<= 1;
    }

    return result;
}

int main(int argc, char* argv[])
{
    uint32_t x = std::stoi(argv[1]);
    uint32_t y = std::stoi(argv[2]);
    
    std::cout << multiply(x, y) << std::endl;

    return 0;
}
