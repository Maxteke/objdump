##
## EPITECH PROJECT, 2019
## PSU_2018_nmobjdump
## File description:
## Makefile
##

NAME	= my_objdump

CC	= gcc

RM	= rm -f

SRCS	= ./src/elf_header.c \
		./src/elf_section.c \
		./src/main.c \
		./src/my_objdump.c \
		./src/calc_flags.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./inc/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
