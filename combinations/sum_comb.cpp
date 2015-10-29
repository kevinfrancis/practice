#include <iostream>
#include <cstdlib>

//#define DBG

void print_buf(const int* buf, int buf_len)
{
    for (int i = 0; i < buf_len; i++)
        std::cout << buf[i] << " ";

    std::cout << std::endl;
}

/**
 * Print all combinations of a fixed size that yield the same sum
 * e.g. To reach sum 5 with a fixed size=3,
 *    this function should produce:
 *        {3,1,1}, {2,2,1}
 * Maintaining ascending order to avoid duplicates
 */
void comb_sum_fixed_size(int* buf, int indx, int sum, int size)
{
#ifdef DBG
    std::cout << "P" << size << "(" << sum << ")" << std::endl;
#endif

    if (size == 1) {
        // Reached leaf.  Set the last item of buf, and print entire buf
        if (indx >= 1 &&
            sum < buf[indx-1])
            return;

        buf[indx] = sum;
#ifdef DBG
        std::cout << "Reached leaf: buf[" << indx << "] = " << sum << std::endl;
#endif
        print_buf(buf, indx+1);
        return;
    }

    for (int i = 1; i < sum; i++) {
        if (indx >= 1 && i < buf[indx - 1])
            continue;
        buf[indx] = i;
#ifdef DBG
        std::cout << "buf[" << indx << "] = " << i << std::endl;
#endif
        comb_sum_fixed_size(buf, indx+1, sum - i, size - 1);
    }

}

/**
 * Print all combinations that yield the same sum
 * Relies on slave function comb_sum_fixed_size
 */
void comb_sum(int sum)
{
    int* buf = new int[sum];

    for (int size = sum; size > 0; size--)
        comb_sum_fixed_size(buf, 0, sum, size);

    delete buf;
}


int main(int argc, char* argv[])
{
    if (argc > 1) {
        int sum = atoi(argv[1]);
        comb_sum(sum);
    } else {
        std::cout << "invalid number of args.  Usage: program $num" << std::endl;
    }
}
