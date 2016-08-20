#include <stdio.h>

int is_big_endian_1(void)
{
    unsigned int x = 0x01020304;
    char* c = (char *) &x;

    return c[0] == 0x01;
}

int is_big_endian_2(void)
{
    union {
        unsigned int x;
        char c[4];
    } u = { 0x01020304 };

    return (u.c[0] == 0x01);
}

int main(void)
{
    printf("is_big_endian_1 = %d\n", is_big_endian_1());
    printf("is_big_endian_2 = %d\n", is_big_endian_2());
    return 0;
}
