/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** main
*/

#include "my_objdump.h"

int err_gest(char *file)
{
    int fd = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        printf("objdump: '%s': no such file\n", file);
    else {
        my_objdump(fd, file);
        close(fd);
    }
    return (0);
}

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        err_gest("a.out");
    else {
        while (av[i] != NULL) {
            err_gest(av[i]);
            i++;
        }
    }
    return (0);
}