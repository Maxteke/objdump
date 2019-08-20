/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
#define MY_OBJDUMP_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <libelf.h>
#include <elf.h>
#include <zconf.h>
#include "sys/mman.h"
#include <ctype.h>
#include <string.h>
#include "my_flags.h"

void my_objdump(int, char *);
void print_section(Elf64_Shdr *, Elf64_Ehdr *, uint8_t *, char *);
void print_header(Elf64_Shdr *, Elf64_Ehdr *, char *);
void print_flags(int);
int flags(Elf64_Ehdr *, Elf64_Shdr *);

#endif /* !MY_OBJDUMP_H_ */
