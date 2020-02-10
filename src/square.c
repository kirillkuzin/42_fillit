/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:43:51 by kirillkuzin       #+#    #+#             */
/*   Updated: 2020/02/10 23:39:40 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			get_square_size(int amount_of_tetrominoes)
{
	return (ft_sqrt(4 * amount_of_tetrominoes));
}

char		**new_square(size_t square_size)
{
	char	**square;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(square = (char**)malloc(sizeof(char*) * (square_size + 1))))
		return (NULL);
	if (!(square[square_size] = (char*)malloc(sizeof(char))))
	{
		free_square(square, square_size);
		return (NULL);
	}
	square[square_size][0] = '\0';
	while (i < square_size)
	{
		if (!(square[i] = (char*)malloc(sizeof(char) * square_size + 1)))
		{
			free_square(square, square_size);
			return (NULL);
		}
		j = 0;
		while (j < square_size)
		{
			square[i][j] = '.';
			j++;
		}
		square[i][j] = '\0';
		i++;
	}
	return (square);
}

void		print_square(char **square)
{
	int		i;

	i = 0;
	while (square[i][0])
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}

void		free_square(char **square, size_t square_size)
{
	size_t		i;

	i = 0;
	if (square)
	{
		while (i < square_size + 1)
		{
			if (square[i])
				free(square[i]);
			i++;
		}
		free(square);
	}
}
