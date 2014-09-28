/*
 * Design an algorithm and write code to remove the duplicate characters in a
 * string without using any additional buffer.
 *
 * NOTE: One or two additional * variables are fine.  An extra copy of the
 * array is not.
 *
 * FOLLOW UP Write the test cases for this method.
 */

#include <stdio.h>
#include <string.h>

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
    char abcd[] = "abcd";
    char aaaa[] = "aaaa";
    char aaabbb[] = "aaabbb";
    char abcdab[] = "abcdab";
    char empty[] = "";

    remove_dup(abcd);
    printf("`abcd` = `%s`\n", abcd);

    remove_dup(aaaa);
    printf("`aaaa` = `%s`\n", aaaa);

    remove_dup(aaabbb);
    printf("`aaabbb` = `%s`\n", aaabbb);

    remove_dup(abcdab);
    printf("`abcdab` = `%s`\n", abcdab);

    remove_dup(empty);
    printf("`` = `%s`\n", empty);

    return 0;
}
