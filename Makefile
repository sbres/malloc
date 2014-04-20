#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbres <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 18:56:49 by sbres             #+#    #+#              #
#    Updated: 2014/02/17 18:56:53 by sbres            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fPIC
SRCS = malloc.c init_pages.c set_header.c ft_tiny_malloc.c ft_medium_malloc.c\
	 ft_big_malloc.c show_alloc_mem.c free.c realoc.c ft_putnbr.c ft_putchar.c
OBJS = $(SRCS:.c=.o)
ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
NAME = libft_malloc_$HOSTTYPE.so

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -shared -lpthread -o $(NAME) $(OBJS)
	ln -s $(NAME) libft_malloc.so
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	$(CC) -g3 $(CFLAGS) $(SRCS)
	gdb $(NAME)

.PHONY: all clean re fclean
