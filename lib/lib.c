#include "lib.h"

#include <stdio.h>
#include <string.h>

void ok_str_eq(struct Test *test, const char *expect, const char *actual)
{
    if (strcmp(expect, actual)) {
        printf("ok expect `%s`, actual `%s`\n", expect, actual);
        ++test->pass;
    } else {
        printf("not ok expect `%s`, actual `%s`\n", expect, actual);
        ++test->fail;
    }
}

void ok_int_eq(struct Test *test, int expect, int actual)
{
    if (expect == actual) {
        printf("ok expect `%d`, actual `%d`\n", expect, actual);
        ++test->pass;
    } else {
        printf("not ok expect `%d`, actual `%d`\n", expect, actual);
        ++test->fail;
    }
}

int get_status(struct Test *test)
{
    if (test->fail) {
        return -1;
    }

    return 0;
}
