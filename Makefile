#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:40:28 by gtandeo           #+#    #+#              #
#    Updated: 2016/05/11 11:41:47 by gtandeo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = malloc.c \
	  free.c \
	  realloc.c \
	  add_block.c \
	  sgt_size.c \
	  show_alloc_mem.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

ifeq ($(HOSTTYPE),)
	export HOSTTYPE=$(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

OBJ = $(SRC:.c=.o)

HEAD = libft_malloc.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ)
	@echo ""
	@echo "\033[33m"$(NAME) Compiled ! "\033[32m"Success
	@test -f libft_malloc.so || ln -s $(NAME) libft_malloc.so
	@echo "\033[33m"libft_malloc.so Created ! "\033[32m"Success

$(OBJ): $(HEAD)
%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[33m"$(NAME) objects Deleted ! "\033[32m"Success

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft_malloc.so
	@echo "\033[33m"$(NAME) Deleted ! "\033[32m"Success
	@echo "\033[33m"libft_malloc.so Deleted ! "\033[32m"Success


re: fclean all

.PHONY: all re fclean clean
