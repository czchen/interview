/*
 * Write a method which finds the maximum of two numbers. You should not use
 * if-else or any other comparison operator
 */

#include "testhelper.h"

int max(int x, int y)
{
    int z = x - y;
    int sign = (z >> (sizeof(z) * 8 - 1)) & 0x1;
    return x - z * sign;
}

int main()
{
    struct Test test = { 0 };

    ok_int_eq(&test, 100, max(-100, 100));
    ok_int_eq(&test, 0, max(-100, 0));
    ok_int_eq(&test, 100, max(0, 100));

    return get_status(&test);
}
