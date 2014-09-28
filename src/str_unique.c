/*
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you can not use additional data structures?
 */

#include <stdio.h>

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
    printf("`abcdef` is %d\n", has_str_all_unique_chars("abcdef"));
    printf("`abcdefa` is %d\n", has_str_all_unique_chars("abcdefa"));
    printf("`` is %d\n", has_str_all_unique_chars(""));

    return 0;
}
