/*
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than the
 * original string, your method should return the original string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "testhelper.h"

int update_compress_buffer(char *buf, size_t buf_len, char chr, int cnt)
{
    int ret = snprintf(buf, buf_len, "%c%d", chr, cnt);
    return ret;
}

char *compress(char *str)
{
    if (!str) {
        return NULL;
    }

    int len = strlen(str);

    char *ret = malloc(len * 2 + 1);
    if (!ret) {
        return NULL;
    }
    int ret_pos = 0;

    int curr_chr = str[0];
    int curr_cnt = 1;

    for (int i = 1; i < len; ++i) {
        if (curr_chr == str[i]) {
            ++curr_cnt;
        } else {
            ret_pos += update_compress_buffer(&ret[ret_pos], len * 2 + 1 - ret_pos, curr_chr, curr_cnt);

            curr_chr = str[i];
            curr_cnt = 1;
        }
    }
    ret_pos += update_compress_buffer(&ret[ret_pos], len * 2 + 1 - ret_pos, curr_chr, curr_cnt);

    return ret;
}

int main()
{
    struct Test test = { 0 };

    char *ret;

    ret = compress("aabcccccaaa");
    ok_str_eq(&test, ret, "a2b1c5a3");
    free(ret);

    ret = compress("");
    ok_str_eq(&test, ret, "");
    free(ret);

    ret = compress("abcdefg");
    ok_str_eq(&test, ret, "a1b1c1d1e1f1g1");
    free(ret);

    return get_status(&test);
}
