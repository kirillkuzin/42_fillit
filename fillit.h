/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/12 23:38:52 by ggeordi          ###   ########.fr       */
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
	int					x_shift;
}						t_tetromino;

typedef struct			s_point
{
	int					i;
	int					j;
}						t_point;

t_list					*read_tetri(int fd, int *amount_of_tetrominoes);
int						tetri_valid(char *line);
int						line_is_valid(char *line, int counter);
t_tetromino				*new_tetromino(char *tetromino_str, char letter);
void					build_tetromino(t_tetromino *tetromino,
						char **tetromino_body, char *tetromino_str,
						char letter);
void					get_shifts(char *tetromino_str,
						int *x_shift, int *y_shift);
void					free_tetromino(void *tetromino_content,
						size_t tetromino_size);
t_list					*save_tetromino(t_list *tetrominoes,
						int *amount_of_tetrominoes, char *buf, int i);
int						get_square_size(int amount_of_tetrominoes);
char					**new_square(size_t square_size);
void					print_square(char **square);
void					*free_square(char **square, size_t square_size);
char					**algorithm(t_list *list_of_tetrominoes,
						char **square, int first);
char					**algorithm_body(t_list *list_of_tetrominoes,
										t_tetromino *tetromino, char **square,
										t_point *point);
int						tetrimino_xshift(t_tetromino *tetrimino);
int						check_fit_tetromino(char **square, int i,
						int j, t_tetromino *tetromino);
void					paste_tetromino(char **square, int i,
						int j, t_tetromino *tetromino);
void					remove_tetromino(char **square, int i,
						int j, t_tetromino *tetromino);
t_point					*create_point(void);
void					free_point(t_point *point);

#endif
