/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:15:27 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/18 14:42:19 by malbert          ###   ########.fr       */
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
	int				first_pos;
	char			**tetromino_body;

	i = 0;
	k = 0;
	first_pos = -1;
	if (!(tetromino_body = new_square(4)))
		return (NULL);
	while (tetromino_str[i])
	{
		if (tetromino_str[i] == '#')
		{
			if (first_pos == -1)
				first_pos = i;
			tetromino_body[k][i - first_pos - k * 5] = '#';
		}
		if (tetromino_str[i] == '\n' && first_pos != -1)
			k++;
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
