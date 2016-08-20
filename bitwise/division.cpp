#include <iostream>
#include <cstdlib>
#include <cstdio>


#define UPPER32(x) ((x) >> 32)
#define LOWER32(x) ((x) & 0xffffffff)

#define GET_BIT(x, i) (((x) >> (i)) & 1)

static inline uint64_t
extract_bits(uint64_t x, int lbit, int rbit)
{
    uint64_t mask = (((uint64_t) 1) << (lbit - rbit + 1)) - 1;

    return ((x >> rbit) & mask);
}

/**
 * Approach 1:  Plain old long-division method.
 *              Goes over each bit
 */
uint64_t div_64_by_8_v1(uint64_t number, uint8_t divisor)
{
    uint32_t remainder = 0;
    uint64_t result = 0;

    for (int i = 0; i < 64; i++) {

        remainder <<= 1;
        result <<= 1;

        if (number & (((uint64_t) 1) << 63))
            remainder |= 1;

        if (divisor <= remainder) {
            result |= 1;
            remainder -= divisor;
        }

        number <<= 1;
    }

    return result;
}


/**
 * Approach 2:  Take advantage of 32 bit division
 * Uses 32-bit division thrice to compute the result
 */
uint64_t div_64_by_8_v2(uint64_t number, uint8_t divisor)
{
    uint32_t remainder = 0;
    uint64_t result = 0;

	/* Extract 24 bits at a time from right to left,
	   and append it to remainder */
	for (int lbit = 63; lbit > 0; lbit -= 24) {

		int rbit = std::max(lbit - 24 + 1, 0);

		uint32_t tmp32 = extract_bits(number, lbit, rbit);
		tmp32 |= (remainder << std::min(24, lbit+1));

		uint32_t quotient = tmp32 / divisor;
		remainder = tmp32 % divisor;

		result |= ((uint64_t) quotient) << rbit;
	}

    return result;
}

/*
 * 1001 / 101
 *   1
 *  
 */
uint32_t divide(uint32_t x, uint32_t y)
{
    uint32_t quotient = 0;
    uint32_t remainder = 0;

    for (int i = 31; i >= 0; i--) {
        quotient <<= 1;
        remainder = (remainder << 1) | GET_BIT(x, i);
        
        if (y <= remainder) {
            quotient |= 1;
            remainder -= y;
        }
    }

    return quotient;
}

int main(int argc, char* argv[])
{

    if (argc < 3) {
        std::cerr << "insufficient args" << std::endl;
    } else {
#if 1
        uint64_t number = atoi(argv[1]); // TODO: Read 64bit in
        uint8_t divisor = atoi(argv[2]);
#else
        uint64_t number = 0xaaaabbbbccccdddd;
        uint8_t divisor = 0x1c;
#endif
        if (divisor != 0) {
            std::cout << "bitwise division  => " << div_64_by_8_v1(number, divisor) << std::endl;
            std::cout << "using 32bit div   => " << div_64_by_8_v2(number, divisor) << std::endl;
            std::cout << "using 32bit/32bit => " << divide(number, divisor) << std::endl;
            std::cout << "normal  division => " << number / divisor << std::endl;
        } else {
            std::cerr << "div by 0 not allowed" << std::endl;
        }
    }
    return 0;
}
