# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 14:12:49 by malbert           #+#    #+#              #
#    Updated: 2020/02/10 23:50:17 by ggeordi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -g
NAME = fillit
SRC = src/algorithm.c src/main.c src/tetromino.c src/reader.c src/square.c
OBJECTS = tetromino.o reader.o square.o main.o algorithm.o

all : $(NAME)

$(NAME) :
		@make -C libft/
		@gcc $(FLAGS) -c $(SRC)
		@gcc $(OBJECTS) libft/libft.a $(FLAGS) -o $(NAME)

clean :
		@rm -f $(OBJECTS)
		@make clean -C libft/

fclean : clean
		@rm -f $(NAME)
		@make fclean -C libft/

re : fclean all
