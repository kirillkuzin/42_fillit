/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:12 by kirillkuzin       #+#    #+#             */
/*   Updated: 2020/01/18 15:30:43 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char		**algorithm(t_list *list_of_tetrominoes, char** square)
{
	t_tetromino		*tetromino;
	char			**filled_square;
	int				i;
	int				j;

	i = 0;
	tetromino = list_of_tetrominoes->content;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			if (square[i][j] == '.')
			{
				if (check_fit_tetromino(square, i, j, tetromino))
				{
					paste_tetromino(square, i, j, tetromino);
					if (!list_of_tetrominoes->next)
						return (square);
					filled_square = algorithm(list_of_tetrominoes->next, square);
					if (!filled_square)
					{
						remove_tetromino(square, i, j, tetromino);
						continue;
					}
					else
						return (filled_square);
				}
				else
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int			check_fit_tetromino(char **square, int i, int j, t_tetromino *tetromino)
{
	int		h;
	int		w;

	h = 0;
	while (h < 4)
	{
		w = 0;
		while (w < 4)
		{
			if (tetromino->body[h][w] == '#' && square[i + h][j + w] != '.')
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

void		paste_tetromino(char **square, int i, int j, t_tetromino *tetromino)
{
	int		h;
	int		w;

	h = 0;
	while (h < 4)
	{
		w = 0;
		while (w < 4)
		{
			if (tetromino->body[h][w] == '#')
				square[i + h][j + w] = '#';
			w++;
		}
		h++;
	}
}

void		remove_tetromino(char **square, int i, int j, t_tetromino *tetromino)
{
	int		h;
	int		w;

	h = 0;
	while (h < 4)
	{
		w = 0;
		while (w < 4)
		{
			if (tetromino->body[h][w] == '#')
				square[i + h][j + w] = '.';
			w++;
		}
		h++;
	}
}
