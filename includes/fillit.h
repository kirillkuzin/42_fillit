/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:50:18 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/15 21:17:34 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// #include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef struct			s_tetromino
{
	char				**body;
	char				letter;
}						t_tetromino;

t_list					**read_tetrominoes(int fd, int *amount_of_tetrominoes);
void					write_tetromino(t_list *elem);
t_tetromino				*new_tetromino();
void					free_tetromino(void *tetromino, size_t tetromino_size);

#endif
