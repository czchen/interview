/*
 * Write a method to replace all spaces in a string with ‘%20’.
 */

#include <stdlib.h>
#include <string.h>

#include "testhelper.h"

char *replace_space(const char *str)
{
    int space_count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            ++space_count;
        }
    }

    char *res = malloc(len + space_count * 2 + 1);
    if (!res) {
        return res;
    }

    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            res[j] = '%';
            ++j;
            res[j] = '2';
            ++j;
            res[j] = '0';
            ++j;
        } else {
            res[j] = str[i];
            ++j;
        }
    }
    res[j] = 0;

    return res;
}

int main()
{
    struct Test test = { 0 };

    char *res;

    res = replace_space("a b c");
    ok_str_eq(&test, "a%20b%20c", res);
    free(res);

    res = replace_space("   ");
    ok_str_eq(&test, "%20%20%20", res);
    free(res);

    res = replace_space("abcd");
    ok_str_eq(&test, "abcd", res);
    free(res);

    return get_status(&test);
}
