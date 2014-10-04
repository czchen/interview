/*
 * Design an algorithm and write code to remove the duplicate characters in a
 * string without using any additional buffer.
 *
 * NOTE: One or two additional * variables are fine.  An extra copy of the
 * array is not.
 *
 * FOLLOW UP Write the test cases for this method.
 */

#include <string.h>

#include "testhelper.h"

void remove_dup(char *str)
{
    int count[0x100] = { 0 };
    int len = strlen(str);

    int j = 0;

    for (int i = 0; i < len; ++i) {
        if (count[(unsigned char) str[i]] == 0) {
            ++count[(unsigned char) str[i]];

            str[j] = str[i];
            ++j;
        }
    }

    str[j] = 0;
}

int main()
{
    struct Test test = { 0 };

    char abcd[] = "abcd";
    char aaaa[] = "aaaa";
    char aaabbb[] = "aaabbb";
    char abcdab[] = "abcdab";
    char empty[] = "";

    remove_dup(abcd);
    ok_str_eq(&test, "abcd", abcd);

    remove_dup(aaaa);
    ok_str_eq(&test, "a", aaaa);

    remove_dup(aaabbb);
    ok_str_eq(&test, "ab", aaabbb);

    remove_dup(abcdab);
    ok_str_eq(&test, "abcd", abcdab);


    remove_dup(empty);
    ok_str_eq(&test, "", empty);

    return get_status(&test);
}
