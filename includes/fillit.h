/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/12 00:07:50 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct			s_tetromino
{
	char				**body;
	char				letter;
	int					width;
	int					height;
}						t_tetromino;

t_list					**read_tetrominoes(int fd, int *amount_of_tetrominoes);
void					write_tetromino(t_list *elem);
t_tetromino				*new_tetromino();
void					free_tetromino(void *tetromino_content, size_t tetromino_size);
int						get_square_size(int amount_of_tetrominoes);
char					**new_square(size_t square_size);
void					print_square(char **square);
char					**algorithm(t_list *list_of_tetrominoes, char** square)

#endif
