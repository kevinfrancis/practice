#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Convert 32 bit integer to string
 * @param x      Input integer (32 bit)
 * @param result result string (if NULL, we allocate space)
 * @return Pointer to the result string
 *         NULL upon memory allocation failure
 */
char* int_to_str(int x, char* result)
{
    const int negative = (x < 0);
    unsigned pow_10_x = 1000000000; /* 10 ** 9 */
    unsigned abs_x;
    int i = 0;

    /* Allocate space for result, if not allocated by caller */
    if (NULL == result) {
        result = (char *) malloc(12);
        if (NULL == result) {
            fprintf(stderr, "malloc failed\n");
            return NULL;
        }
    }

    /* Kick out x==0 case */
    if (x == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    /* Fix abs_x */
    if (x > 0 || x == INT_MIN)
        abs_x = x;
    else
        abs_x = -x;

    /* Find the highest power of 10 less than x */
    while (pow_10_x > abs_x)
        pow_10_x /= 10;

    /* If negative, write '-' sign first */
    if (negative)
        result[i++] = '-';

    /* Extract digits from left to right */
    do {
        int digit = abs_x / pow_10_x; // Extract most significant digit (MSD)
        result[i++] = '0' + digit;    // Convert digit to char, and write digit
        abs_x -= digit * pow_10_x;    // Chop off most significant digit
    } while (pow_10_x /= 10);         // Next power of 10

    result[i++] = '\0'; // Terminate string !

    return result;
}


/**
 * main
 * Test the int_to_str function
 */
int main(void)
{
    int arr[] = {0, 1, 10, -10, 2000, -34344, 23479, 
                 1000000000, -1000000000,
                 1234567890, -1234567890,
                 INT_MAX, INT_MIN};
    const int num_tests = sizeof(arr) / sizeof(arr[0]);
    int i;

    for (i = 0; i < num_tests; i++) {
        char* str = int_to_str(arr[i], NULL);
        if (str) {
            printf("%11d : %11s\n", arr[i], str);
            free(str);
        }
    }

    return 0;
}
