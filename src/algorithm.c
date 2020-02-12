/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:12 by kirillkuzin       #+#    #+#             */
/*   Updated: 2020/02/12 23:42:45 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char				**algorithm(t_list *list_of_tetrominoes, \
						char **square, int first)
{
	t_tetromino		*tetromino;
	char			**filled_square;
	t_point			*point;

	point = create_point();
	tetromino = list_of_tetrominoes->content;
	while (square[point->i])
	{
		point->j = 0;
		while (square[point->i][point->j])
		{
			if (square[point->i][point->j] == '.')
			{
				if (first == 1)
					tetromino->x_shift = 0;
				if ((filled_square = algorithm_body(list_of_tetrominoes,
				tetromino, square, point)))
					return (filled_square);
			}
			point->j++;
		}
		point->i++;
	}
	free_point(point);
	return (NULL);
}

char				**algorithm_body(t_list *list_of_tetrominoes,
									t_tetromino *tetromino, char **square,
									t_point *point)
{
	char			**filled_square;

	if (check_fit_tetromino(square, point->i, point->j, tetromino))
	{
		paste_tetromino(square, point->i, point->j, tetromino);
		if (!list_of_tetrominoes->next)
		{
			free_point(point);
			return (square);
		}
		filled_square = algorithm(list_of_tetrominoes->next, square, 0);
		if (!filled_square)
			remove_tetromino(square, point->i, point->j, tetromino);
		else
		{
			free_point(point);
			return (filled_square);
		}
	}
	return (NULL);
}
