# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 14:31:34 by jmaynard          #+#    #+#              #
#    Updated: 2019/07/30 10:57:54 by jmaynard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C src/checker/
	@cp src/checker/checker .
	@make -C src/push_swap/
	@cp src/push_swap/push_swap .

clean:
	@make -C src/checker/ $@
	@make -C src/push_swap/ $@

fclean:
	@make -C src/checker/ $@
	@rm -rf checker
	@make -C src/push_swap/ $@
	@rm -rf push_swap

re: fclean all