#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:40:28 by gtandeo           #+#    #+#              #
#    Updated: 2016/01/21 23:55:14 by gtandeo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = free.c \
	  malloc.c \
	  realloc.c \
	  t_sigleton.c \
	  s_sigleton.c \
	  l_sigleton.c

CFLAGS = -Wall -Werror -Wextra

ifeq ($(HOSTTYPE),)
	export HOSTTYPE=$(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LIB = libft.a

LIBDIR = libft/

OBJ = $(SRC:.c=.o)

HEAD = libft_malloc.h

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIBDIR) fclean
	@make -C $(LIBDIR)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"$(NAME) Compiled ! "\033[32m"Success
	@test -f libft_malloc.so || ln -s $(NAME) libft_malloc.so
	@echo "\033[33m"libft_malloc.so Created ! "\033[32m"Success

$(OBJ): $(HEAD)

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@make -C $(LIBDIR) clean
	@/bin/rm -f $(OBJ)
	@echo "\033[33m"$(NAME) objects Deleted ! "\033[32m"Success

fclean: clean
	@make -C $(LIBDIR) fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft_malloc.so
	@echo "\033[33m"$(NAME) Deleted ! "\033[32m"Success
	@echo "\033[33m"libft_malloc.so Deleted ! "\033[32m"Success


re: fclean all

.PHONY: all re fclean clean

