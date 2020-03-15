# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 14:36:10 by jmaynard          #+#    #+#              #
#    Updated: 2019/07/31 16:42:32 by jmaynard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
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

SRC_P = push_swap.c \
		sort_a.c \
		simple.c simple_up.c simple_down.c simple_comm.c \
		mediana.c \
		sort_b.c \
		sort_add.c \
		sort_move.c improve.c \
		qs_cont.c imp_rot.c
		
OBJS_P = $(SRC_P:.c=.o)
OBJS = $(SCRFILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L ../../libft/ -lft
LIBFT = ../../libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(OBJS_P)
	@$(CC) -o $(NAME) $(OBJS) $(OBJS_P) $(LDFLAGS)

$(LIBFT):
	@$(MAKE) -C ../../libft/

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C ../../libft/ $@
	@/bin/rm -f $(OBJS) $(OBJS_P)

fclean: clean
	@$(MAKE) -C ../../libft/ $@
	@/bin/rm -f $(NAME) 

re: fclean all

.PHONY: all, clean, fclean, re