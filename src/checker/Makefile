# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 14:57:31 by jmaynard          #+#    #+#              #
#    Updated: 2019/07/31 16:42:34 by jmaynard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
MAKE = make
SRCDIR = ..
HEAD = ../push_swap.h
SCRFILES = $(addprefix $(SRCDIR)/, $(SRC))
SRC =	stack.c \
		swap_push.c \
		rotate.c \
		create_valid_stack.c \
		ft_atoi_large.c \
		visual.c

SRC_C = checker.c \
		commands.c

OBJS_C = $(SRC_C:.c=.o)
OBJS = $(SCRFILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L ../../libft/ -lft
LIBFT = ../../libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(OBJS_C)
	@$(CC) -o $(NAME) $(OBJS) $(OBJS_C) $(LDFLAGS)

$(LIBFT):
	@$(MAKE) -C ../../libft/

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C ../../libft/ $@
	@/bin/rm -f $(OBJS) $(OBJS_C)

fclean: clean
	@$(MAKE) -C ../../libft/ $@
	@/bin/rm -f $(NAME) 

re: fclean all

.PHONY: all, clean, fclean, re