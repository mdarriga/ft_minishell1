# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 17:55:37 by bbotella          #+#    #+#              #
#    Updated: 2015/02/03 14:09:42 by mdarriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
CCLIB = -Llibft -lft
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC +=	main.c
SRC	+=	ft_sh1.c
SRC +=	check_arg.c
SRC +=	setenv.c
SRC +=	unsetenv.c
SRC +=	get_next_line.c
SRC +=	cd.c
SRC +=	change_pwd.c
SRC +=	exec_path.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) $(CCLIB) -o $(NAME) $(OBJ)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
