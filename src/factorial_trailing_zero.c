/*
 * Write an algorithm which computes the number of trailing zeros in n
 * factorial.
 */

#include "testhelper.h"

int trailing_factorial_zero_count(int x)
{
    int count = 0;

    while (x) {
        x /= 5;
        count += x;
    }

    return count;
}

int main()
{
    struct Test test = { 0 };

    ok_int_eq(&test, 1, trailing_factorial_zero_count(5));
    ok_int_eq(&test, 2, trailing_factorial_zero_count(10));
    ok_int_eq(&test, 6, trailing_factorial_zero_count(25));

    return get_status(&test);
}
