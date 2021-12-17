# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gradagas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:47:19 by gradagas          #+#    #+#              #
#    Updated: 2021/12/06 18:47:21 by gradagas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all	:
	gcc -Wall -Wextra -Werror get_next_line_utils.c get_next_line.h get_next_line.c main_test.c
	./a.out tests/41_with_nl | cat -e