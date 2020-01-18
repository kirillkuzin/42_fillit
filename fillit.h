/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/18 14:41:33 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_tetromino
{
	char				**body;
	char				letter;
	int					width;
	int					height;
}						t_tetromino;

t_list					**read_tetrominoes(int fd, int *amount_of_tetrominoes);
void					write_tetromino(t_list *elem);
t_tetromino				*new_tetromino(char *tetromino_str, char letter);
char					**build_tetromino(char *tetromino_str);
void					free_tetromino(void *tetromino_content, size_t tetromino_size);
int						get_square_size(int amount_of_tetrominoes);
char					**new_square(size_t square_size);
void					print_square(char **square);
char					**algorithm(t_list *list_of_tetrominoes, char** square);
int						check_fit_tetromino(char **square, int i, int j, t_tetromino *tetromino);
void					paste_tetromino(char **square, int i, int j, t_tetromino *tetromino);
void					remove_tetromino(char **square, int i, int j, t_tetromino *tetromino);

#endif
