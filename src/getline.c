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
    static int fdsave = -1;
    char *to_return;

    if (fd == -1) {
        if (carry == NULL) {
            free(carry);
        }
            return (NULL);
    }
    if (fd != fdsave) {
        free(carry);
        carry = NULL;
        fdsave = fd;
    }
    if (carry == NULL) {
        to_return = loop_read_until(fd, '\n');
    } else {
        to_return = carry;
        to_return = strdupcat(carry, loop_read_until(fd, '\n'));
    }
    carry = stu_strdup(split_inplace(to_return, '\n'));
    return (to_return);
}
