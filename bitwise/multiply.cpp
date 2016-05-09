#include <iostream>


/*
 * Addition
 */
static inline uint32_t add(uint32_t x, uint32_t y)
{
    uint32_t result = 0;
    uint32_t result_mask = 1;
    int sum_bit = 0, carry_bit = 0;
    
    for (; x | y; x >>= 1, y >>= 1) {
        uint32_t x_bit = x & 1;
        uint32_t y_bit = y & 1;
        
        sum_bit = x_bit ^ y_bit ^ carry_bit;
        carry_bit = (((x_bit & y_bit) == 0) ? (carry_bit & (x_bit | y_bit)): 1);

		if (sum_bit) {
			result |= result_mask;
		}

		result_mask <<= 1;
    }

	if (carry_bit) {
		result |= result_mask;
	}

    return result;
}



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
#ifdef ADDITION_ALLOWED
            result += x;
#else
            result = add(result, x);
#endif
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
    std::cout << "Correct ans = " << x * y << std::endl;

    return 0;
}
