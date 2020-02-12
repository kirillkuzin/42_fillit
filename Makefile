# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 14:12:49 by malbert           #+#    #+#              #
#    Updated: 2020/02/12 23:28:46 by ggeordi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -g
CFLAGS += -I libft/includes/
NAME = fillit
SRC = src/algorithm.c src/main.c src/tetromino.c src/reader.c src/square.c src/algorithm_utils.c src/point.c
OBJECTS = tetromino.o reader.o square.o main.o algorithm.o algorithm_utils.o point.o

all : $(NAME)

%.o: %.c
		@gcc -c $(CFLAGS) $< -o $@

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
