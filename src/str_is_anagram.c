/*
 * Write a method to decide if two strings are anagrams or not.
 */

#include "testhelper.h"

int is_anagram(const char *str1, const char *str2)
{
    int count[0x100] = { 0 };

    for (; *str1; ++str1) {
        ++count[(unsigned char) *str1];
    }

    for (; *str2; ++str2) {
        --count[(unsigned char) *str2];
    }

    for (int i = 0; i < sizeof(count) / sizeof(count[0]); ++i) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    struct Test test = { 0 };

    ok_int_eq(&test, 1, is_anagram("abcd", "dcba"));
    ok_int_eq(&test, 0, is_anagram("abcd", "abcde"));
    ok_int_eq(&test, 1, is_anagram("", ""));

    return get_status(&test);
}
