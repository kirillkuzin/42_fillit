/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:12 by kirillkuzin       #+#    #+#             */
/*   Updated: 2020/02/06 23:04:26 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char		**algorithm(t_list *list_of_tetrominoes, char **square, int first)
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
				if (check_fit_tetromino(square, i, j, tetromino, first))
				{
					paste_tetromino(square, i, j, tetromino, first);
					if (!list_of_tetrominoes->next)
						return (square);
					filled_square = algorithm(list_of_tetrominoes->next,
					square, 0);
					if (!filled_square)
						remove_tetromino(square, i, j, tetromino, first);
					else
					return (filled_square);
				}
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

int			check_fit_tetromino(char **square, int i,
			int j, t_tetromino *tetromino, int first)
{
	int		h;
	int		w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (first == 1)
			{
				if (tetromino->body[h][w] != '.' && square[i + h][j + w] != '.')
					return (0);
			}
			else
			{
				if (tetromino->body[h][w] != '.'
				&& square[i + h][j + w - tetrimino_xshift(tetromino)] != '.')
					return (0);
			}
			w++;
		}
		h++;
	}
	return (1);
}

int			tetrimino_xshift(t_tetromino *tetrimino)
{
	int x_shift;

	x_shift = 0;
	while (tetrimino->body[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

void		paste_tetromino(char **square, int i,
			int j, t_tetromino *tetromino, int first)
{
	int		h;
	int		w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (tetromino->body[h][w] != '.')
			{
				if (first == 1)
					square[i + h][j + w] = tetromino->body[h][w];
				else
					square[i + h][j + w - tetrimino_xshift(tetromino)] = tetromino->body[h][w];
			}
			w++;
		}
		h++;
	}
}

void		remove_tetromino(char **square, int i, int j,
			t_tetromino *tetromino, int first)
{
	int		h;
	int		w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (tetromino->body[h][w] != '.')
			{
				if (first == 1)
					square[i + h][j + w] = '.';
				else
					square[i + h][j + w - tetrimino_xshift(tetromino)] = '.';
			}
			w++;
		}
		h++;
	}
}
