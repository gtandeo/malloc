#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:40:28 by gtandeo           #+#    #+#              #
#    Updated: 2016/01/04 05:35:24 by gtandeo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = free.c \
	  malloc.c \
	  realloc.c

CFLAGS = -Wall -Werror -Wextra

NAME = ft_alloc.a

OBJ = $(SRC:.c=.o)

HEAD = ft_alloc.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"ft_alloc.a Compiled ! "\033[32m"Success

$(OBJ): $(HEAD)

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@echo "\033[33m"Objects Deleted ! "\033[32m"Success
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean

