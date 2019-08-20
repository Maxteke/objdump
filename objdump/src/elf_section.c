/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** elf_section
*/

#include "my_objdump.h"

void print_ascii(Elf64_Shdr *shdr, uint8_t *data, int i, size_t k)
{
    size_t line = 0;

    printf(" ");
    while (k < shdr[i].sh_offset + shdr[i].sh_size && line < 16) {
        if (isprint(data[k]))
            printf("%c", data[k]);
        else
            printf(".");
        k++;
        line++;
    }
    while (line < 16) {
        printf(" ");
        line++;
    }
    printf("\n");
}

void print_shdr(Elf64_Shdr *shdr, uint8_t *data, int i)
{
    size_t k = shdr[i].sh_offset;
    size_t line = 0;

    while (k < shdr[i].sh_offset + shdr[i].sh_size) {
        printf(" %04lx ", shdr[i].sh_addr + (k - shdr[i].sh_offset));
        size_t tmp = k;
        size_t col = 0;
        while ((col + 1) % 5 != 0) {
            if (k < shdr[i].sh_offset + shdr[i].sh_size)
                printf("%02hhx", data[k]);
            else
                printf("  ");
            line++;
            k++;
            line % 4 == 0 ? printf(" ") : 0;
            line % 4 == 0 ? col++ : 0;
        }
        print_ascii(shdr, data, i, tmp);
    }
}

int check_section(char *name)
{
    if (!strcmp(name, ".strtab") || !strcmp(name, ".shstrtab")) {
        return (1);
    }
    return (0);
}

int check_file(char *name)
{
    if (strcmp(".o", &name[strlen(name) - 2]))
        return (0);
    return (1);
}

void print_section(Elf64_Shdr *shdr, Elf64_Ehdr *elf,
                    uint8_t *data, char *file)
{
    char *strTab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
    int shNum = elf->e_shnum;

    for (int i = 0; i < shNum; i++) {
        if (strTab[shdr[i].sh_name] && shdr[i].sh_type != SHT_NOBITS
            && shdr[i].sh_type != SHT_SYMTAB && shdr[i].sh_size > 0
            && !check_section(&strTab[shdr[i].sh_name])) {
                if (check_file(file)) {
                    if (shdr[i].sh_type != SHT_RELA) {
                        printf("Contents of section %s:\n",
                                &strTab[shdr[i].sh_name]);
                        print_shdr(shdr, data, i);
                    }
                } else {
                    printf("Contents of section %s:\n",
                            &strTab[shdr[i].sh_name]);
                    print_shdr(shdr, data, i);
                }
        }
    }
}