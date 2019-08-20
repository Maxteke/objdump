/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** calc_flags
*/

#include "my_objdump.h"

int flags(Elf64_Ehdr *elf, Elf64_Shdr *shdr)
{
    int ret = 0;

    if (elf->e_type == ET_EXEC)
        ret |= EXEC_P;
    if (elf->e_type == ET_DYN)
        ret |= DYNAMIC;
    if (elf->e_phnum > 0)
        ret |= D_PAGED;
    if (elf->e_type == ET_REL)
        ret |= HAS_RELOC;
    for (size_t i = 0; i < elf->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            ret |= HAS_SYMS;
    }
    return (ret);
}

int nb_flags(int flags)
{
    int i = 0;

    flags & HAS_RELOC ? i++ : 0;
    flags & HAS_SYMS ? i++ : 0;
    flags & DYNAMIC ? i++ : 0;
    flags & D_PAGED ? i++ : 0;
    return (i);
}

void print_flags(int flags)
{
    int nb = nb_flags(flags);

    if (flags & HAS_RELOC)
        --nb == 0 ? printf("HAS_RELOC\n") : printf("HAS_RELOC, ");
    if (flags & HAS_SYMS)
        --nb == 0 ? printf("HAS_SYMS\n") : printf("HAS_SYMS, ");
    if (flags & DYNAMIC)
        --nb == 0 ? printf("DYNAMIC\n") : printf("DYNAMIC, ");
    if (flags & D_PAGED)
        --nb == 0 ? printf("D_PAGED\n") : printf("D_PAGED, ");
}