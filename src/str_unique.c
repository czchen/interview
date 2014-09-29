/*
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you can not use additional data structures?
 */

#include <stdio.h>

#include "testhelper.h"

int has_str_all_unique_chars(const char *str)
{
    int count[0x100] = { 0 };

    for (; *str; ++str) {
        if (count[(unsigned char) *str]) {
            return 0;
        }

        ++count[(unsigned char) *str];
    }

    return 1;
}

int main()
{
    struct Test test = { 0 };

    ok_int_eq(&test, 1, has_str_all_unique_chars("abcdef"));
    ok_int_eq(&test, 0, has_str_all_unique_chars("abcdefa"));
    ok_int_eq(&test, 1, has_str_all_unique_chars(""));

    return get_status(&test);
}
