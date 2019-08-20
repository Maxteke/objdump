/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** elf_header
*/

#include "my_objdump.h"

char *get_format(int idt)
{
    if (idt == ELFCLASS32)
        return ("elf32-x86-64");
    else if (idt == ELFCLASS64)
        return ("elf64-x86-64");
    return ("unknow");
}

char *get_engine(int eng)
{
    if (eng == EM_X86_64)
        return ("i386:x86-64");
    return ("unknown");
}

void print_header(Elf64_Shdr *shdr, Elf64_Ehdr *elf, char *file)
{
    printf("\n%s:     file format %s\n", file,
            get_format(elf->e_ident[EI_CLASS]));
    printf("architecture: %s, flags 0x%08x:\n", get_engine(elf->e_machine),
            flags(elf, shdr));
    print_flags(flags(elf, shdr));
    printf("start address 0x%016lx\n\n", elf->e_entry);
}