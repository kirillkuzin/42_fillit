/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:15:27 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/22 21:33:24 by ggeordi          ###   ########.fr       */
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
	if (!(tetromino->body = build_tetromino(tetromino_str)))
	{
		free_tetromino(tetromino, sizeof(tetromino));
		return (NULL);
	}
	tetromino->letter = letter;
	tetromino->width = 4;
	tetromino->height = 4;
	return (tetromino);
}

char			**build_tetromino(char *tetromino_str)
{
	int				i;
	int				k;
	int				x_shift;
	int				c;
	int				j;
	char			**tetromino_body;

	i = 0;
	k = 0;
	c = -1;
	x_shift = -1;
	if (!(tetromino_body = new_square(4)))
		return (NULL);
	ft_putstr(tetromino_str);
	while (tetromino_str[i])
	{
		if (tetromino_str[i] == '#')
		{
			if (c = -1 && (i < x_shift || x_shift == -1))
				x_shift = i;
			c = -1;
		}
		if (tetromino_str[i] == '\n')
		{
			k++;
			c = -1;
		}
		i++;
	}
	return (tetromino_body);
}

void		free_tetromino(void *tetromino_content, size_t tetromino_size)
{
	t_tetromino		*tetromino;
	int				i;

	i = 0;

	if (tetromino_size)
	{
		tetromino = (t_tetromino*)tetromino_content;
		while (i < 5)
		{
			ft_strdel(&(tetromino->body[i]));
			i++;
		}
		ft_memdel((void**)&tetromino);
	}
}
