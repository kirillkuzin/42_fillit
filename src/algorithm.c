/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirillkuzin <kirillkuzin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:07:12 by kirillkuzin       #+#    #+#             */
/*   Updated: 2019/12/19 16:04:10 by kirillkuzin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**algorithm(t_list *list_of_tetrominoes, char** square, size_t square_size)
{
	t_tetromino		*tetromino;
	int				i;
	int				j;
	int				k;

	/* Берем пришедший элемент */
	while (list_of_tetrominoes)
	{
		tetromino = (t_tetromino*)list_of_tetrominoes->content;
		/* Пытаемся вставить тетромину */
		i = 0;
		while (i < 4)
		{
			j = 0;
			/* Пока не дошли до конца строки и текущий символ - точка */
			while (j < 4 && square[i][j] == '.')
			{
				/* Меняем текущий символ на решетку */
				square[i][j] = '#';
				j++;
			}
			/* Если мы прошли количество символов, которое больше или равно
			длине тетромины, а так же если количество оставшихся строк больше
			или равно высоте тетромины, то переходим на следующую строку */
			if (j >= tetromino->width && 4 - i >= tetromino->height - 1)
				i++;
			else
				return (NULL);
		}
		square = algorithm(list_of_tetrominoes->next, square);
		if (!square)
		{
			square = new_square(square_size);
			list_of_tetrominoes = list_of_tetrominoes->next;
		}
	}
	return (square);
}
