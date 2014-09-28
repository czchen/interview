/*
 * Write code to reverse a C-Style String. (C-String means that “abcd” is
 * represented as five characters, including the null character.)
 */
#include <stdio.h>
#include <string.h>

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
    char abcd[] = "abcd";
    char abcde[] = "abcde";
    char empty[] = "";

    reverse_str(abcd);
    printf("`abcd` = `%s`\n", abcd);

    reverse_str(abcde);
    printf("`abcde` = `%s`\n", abcde);

    reverse_str(empty);
    printf("`` = `%s`\n", empty);

    return 0;
}
