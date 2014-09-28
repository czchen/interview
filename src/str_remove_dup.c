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

    for (int i = 0; i < len;) {
        if (count[(unsigned char) str[i]] > 0) {
            memmove(str+i, str+i+1, len-i);
            --len;
        } else {
            ++count[(unsigned char) str[i]];
            ++i;
        }
    }
}

int main()
{
    char abcd[] = "abcd";
    char abcdab[] = "abcdab";
    char empty[] = "";

    remove_dup(abcd);
    printf("`abcd` = `%s`\n", abcd);

    remove_dup(abcdab);
    printf("`abcdab` = `%s`\n", abcdab);

    remove_dup(empty);
    printf("`` = `%s`\n", empty);

    return 0;
}
