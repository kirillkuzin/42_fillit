/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/06 22:56:08 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_tetromino
{
	char				**body;
}						t_tetromino;

t_list					**read_tetri(int fd, int *amount_of_tetrominoes);
int						tetri_valid(char *line);
int						line_is_valid(char *line, int counter);
t_tetromino				*new_tetromino(char *tetromino_str, char letter);
void					build_tetromino(char **tetromino_body,
						char *tetromino_str, char letter);
void					get_shifts(char *tetromino_str, int *x_shift,
						int *y_shift);
void					free_tetromino(void *tetromino_content,
						size_t tetromino_size);
int						get_square_size(int amount_of_tetrominoes);
char					**new_square(size_t square_size);
void					print_square(char **square);
char					**algorithm(t_list *list_of_tetrominoes,
						char **square, int first);
int						tetrimino_xshift(t_tetromino *tetrimino);
int						check_fit_tetromino(char **square, int i, int j,
						t_tetromino *tetromino, int first);
void					paste_tetromino(char **square, int i, int j,
						t_tetromino *tetromino, int first);
void					remove_tetromino(char **square, int i, int j,
						t_tetromino *tetromino, int first);

#endif
