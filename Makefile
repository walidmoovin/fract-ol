# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 14:19:51 by wbekkal           #+#    #+#              #
#    Updated: 2022/01/04 12:33:56 by wbekkal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = fractol.c \
	fractol_utilities.c sets.c fractol_utilities2.c
HEADERS = fractol.h
CFLAGS = -Wall -Werror -Wextra
all: # compile all your c files using CFLAGS
	@gcc $(CFLAGS) -o $(NAME) $(SRCS) -lmlx -framework OpenGL -framework AppKit
help: # print help on Makefile
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t20
re:	fclean
	@gcc $(CFLAGS) -o $(NAME) $(SRCS) -lmlx -framework OpenGL -framework AppKit
clean:
fclean: # clean generated files
	@rm -f $(NAME)
.PHONY: all clean fclean re