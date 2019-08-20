/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** my_objdump
*/

#include "my_objdump.h"

void my_objdump(int fd, char *file)
{
    int filesize = lseek(fd, 0, SEEK_END);
    void *data = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);
    Elf64_Ehdr *elf = (Elf64_Ehdr *)(data);
    Elf64_Shdr *shdr = (Elf64_Shdr *)(data + elf->e_shoff);

    print_header(shdr, elf, file);
    print_section(shdr, elf, (uint8_t *)data, file);
}