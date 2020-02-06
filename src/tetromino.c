/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:15:27 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/06 23:00:39 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_tetromino		*new_tetromino(char *tetromino_str, char letter)
{
	t_tetromino		*tetromino;
	int				i;

	i = 0;
	if (!(tetromino = (t_tetromino*)malloc(sizeof(t_tetromino))))
		return (NULL);
	if (!(tetromino->body = new_square(4)))
	{
		free_tetromino(tetromino, sizeof(tetromino));
		return (NULL);
	}
	if (!tetromino->body)
	{
		free_tetromino(tetromino, sizeof(tetromino));
		return (NULL);
	}
	build_tetromino(tetromino->body, tetromino_str, letter);
	return (tetromino);
}

void			build_tetromino(char **tetromino_body,
				char *tetromino_str, char letter)
{
	int				i;
	int				k;
	int				x_shift;
	int				y_shift;

	i = 0;
	k = 0;
	x_shift = 10;
	y_shift = -1;
	get_shifts(tetromino_str, &x_shift, &y_shift);
	while (tetromino_str[i])
	{
		if (tetromino_str[i] == '#')
		{
			tetromino_body[k - y_shift][i - k * 5 - x_shift] = letter;
		}
		else if (tetromino_str[i] == '\n')
			k++;
		i++;
	}
}

void			get_shifts(char *tetromino_str, int *x_shift, int *y_shift)
{
	int				i;
	int				k;

	i = 0;
	k = 0;
	while (tetromino_str[i])
	{
		if (tetromino_str[i] == '#')
		{
			if (k < *x_shift)
				*x_shift = k;
			if (*y_shift == -1)
				*y_shift = i / 5;
		}
		else if (tetromino_str[i] == '\n')
			k = 0;
		else
			k++;
		i++;
	}
}

void			free_tetromino(void *tetromino_content, size_t tetromino_size)
{
	t_tetromino		*tetromino;
	int				i;

	tetromino = (t_tetromino*)tetromino_content;
	i = tetromino_size;
	i = 0;
	while (i < 5)
	{
		ft_strdel(&(tetromino->body[i]));
		i++;
	}
	ft_memdel((void**)&tetromino);
}
