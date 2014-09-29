#pragma once

struct Test {
    int pass;
    int fail;
};

void ok_str_eq(struct Test *test, const char *expect, const char *actual);
void ok_int_eq(struct Test *test, int expect, int actual);

int get_status(struct Test *test);
