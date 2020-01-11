/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:15:27 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/12 00:06:37 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*new_tetromino()
{
	t_tetromino		*tetromino;
	int				i;

	i = 0;
	if (!(tetromino = (t_tetromino*)malloc(sizeof(t_tetromino))))
		return (NULL);
	if (!(tetromino->body = (char**)malloc(sizeof(char*) * 5)))
	{
		free(tetromino);
		return (NULL);
	}
	while (i < 4)
	{
		if (!(tetromino->body[i] = (char*)malloc(sizeof(char) * 5)))
		{
			free_tetromino(tetromino, sizeof(tetromino));
			return (NULL);
		}
		tetromino->body[i][4] = '\0';
		i++;
	}
	return (tetromino);
}

void		free_tetromino(void *tetromino_content, size_t tetromino_size)
{
	t_tetromino		*tetromino;
	int				i;

	i = 0;
	tetromino = (t_tetromino*)tetromino_content;
	while (i < 5)
	{
		ft_strdel(&(tetromino->body[i]));
		i++;
	}
	ft_memdel((void**)&tetromino);
}
