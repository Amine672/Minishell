# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/08 14:59:45 by akabbouc          #+#    #+#              #
#    Updated: 2017/05/15 00:49:49 by akabbouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc


INCLUDES = "libft/includes"

SECONDIN = "includes"

FLAGS = -Wall -Wextra -Werror -g3

SRC = 	main.c\
		minishell.c\
		add_list.c\
		display.c\
		parser.c\
		error.c\
		tools.c\
		tools2.c\
		tools3.c\
		tools4.c\
		setenv.c\
		cd_echo.c\
		pwd_oldpwd.c\
		pwd_oldpwd2.c\

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lft -L ./libft -I $(INCLUDES) -I $(SECONDIN)

%.o:%.c
	gcc -c $(FLAGS) -I $(INCLUDES) -I $(SECONDIN) $< -o $@ 

clean :
	make -C libft/ fclean
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
