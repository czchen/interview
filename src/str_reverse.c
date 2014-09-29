/*
 * Write code to reverse a C-Style String. (C-String means that “abcd” is
 * represented as five characters, including the null character.)
 */
#include <stdio.h>
#include <string.h>

#include "testhelper.h"

void reverse_str(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; ++i) {
        char tmp = str[i];

        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
}

int main()
{
    struct Test test = { 0 };

    char abcd[] = "abcd";
    char abcde[] = "abcde";
    char empty[] = "";

    reverse_str(abcd);
    ok_str_eq(&test, "dcba", abcd);

    reverse_str(abcde);
    ok_str_eq(&test, "edcba", abcde);

    reverse_str(empty);
    ok_str_eq(&test, "", empty);

    return get_status(&test);
}
