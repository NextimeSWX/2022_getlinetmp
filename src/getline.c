/*
 * E89 Pedagogical & Technical Lab
 * project:     Getline
 * created on:  2023-05-04 - 15:44 +0200
 * 1st author:  evan.lebihan - evan.lebihan
 * description: Getline.c
 */

#include "stu.h"

char *stu_getline(int fd)
{
    static char *carry = NULL;
    static int fdsave = 0;
    char *str1;
    char *str2;

    if (fd == -1) {
        free(carry);
        return (NULL);
    }
    if (fd != fdsave) {
        free(carry);
        fdsave = fd;
        carry = NULL;
    }
    if (carry == NULL) {
        str1 = loop_read_until(fd, '\n');
        free(carry);
        carry = stu_strdup(split_inplace(str1, '\n'));
        return (str1);
    } else {
        str1 = stu_strdup(carry);
        if (stu_strchr(carry, '\n')) {
            free(carry);
            carry = stu_strdup(split_inplace(str1, '\n'));
            return (str1);
        }
        str2 = str1;
        str1 = strdupcat(str1, loop_read_until(fd, '\n'));
        free(str2);
        free(carry);
        carry = stu_strdup(split_inplace(str1, '\n'));
        return (str1);
    }
}
