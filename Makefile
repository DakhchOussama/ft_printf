# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odakhch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 21:13:10 by odakhch           #+#    #+#              #
#    Updated: 2021/12/13 21:36:16 by odakhch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC = ft_printf.c ft_printf_util.c ft_printf_util2.c ft_printf_bonus.c

OBJECTS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	ar rcs $(NAME) $?
.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

bonus: all