##
## EPITECH PROJECT, 2019
## PSU_2018_nmobjdump
## File description:
## Makefile
##

NAME_OBJ	= my_objdump

CC	= gcc

RM	= rm -f

SRCS_OBJ	= ./objdump/src/main.c \
		./objdump/src/my_objdump.c	\
		./objdump/src/elf_header.c	\
		./objdump/src/elf_section.c	\
		./objdump/src/calc_flags.c

SRCS_NM	= ./nm/main.c

OBJS_OBJ	= $(SRCS_OBJ:.c=.o)

CFLAGS = -I ./objdump/inc
CFLAGS += -Wall -Wextra

all: objdump

objdump: $(NAME_OBJ)

$(NAME_OBJ): $(OBJS_OBJ)
	$(CC) $(OBJS_OBJ) -o $(NAME_OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJS_OBJ)

fclean: clean
	$(RM) $(NAME_OBJ)

re: fclean all

.PHONY: all clean fclean re
