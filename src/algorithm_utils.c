/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:10:23 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/12 21:35:46 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int					check_fit_tetromino(char **square, int i,
					int j, t_tetromino *tetromino)
{
	int				h;
	int				w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (tetromino->body[h][w] != '.' &&
			square[i + h][j + w - tetromino->x_shift] != '.')
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

void				paste_tetromino(char **square, int i,
					int j, t_tetromino *tetromino)
{
	int				h;
	int				w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (tetromino->body[h][w] != '.')
			{
				square[i + h][j + w - tetromino->x_shift] = \
					tetromino->body[h][w];
			}
			w++;
		}
		h++;
	}
}

void				remove_tetromino(char **square, int i,
					int j, t_tetromino *tetromino)
{
	int				h;
	int				w;

	h = 0;
	while (tetromino->body[h][0] != '\0')
	{
		w = 0;
		while (tetromino->body[h][w] != '\0')
		{
			if (tetromino->body[h][w] != '.')
			{
				square[i + h][j + w - tetromino->x_shift] = '.';
			}
			w++;
		}
		h++;
	}
}
