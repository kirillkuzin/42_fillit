/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirillkuzin <kirillkuzin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:43:51 by kirillkuzin       #+#    #+#             */
/*   Updated: 2019/12/16 17:22:08 by kirillkuzin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**new_square(size_t square_size)
{
	char	**square;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(square = (char**)malloc(sizeof(char*) * (square_size + 1))))
		return (NULL);
	square[square_size] = (char*)malloc(sizeof(char));
	square[square_size][0] = '\0';
	while (i < square_size)
	{
		square[i] = ft_strnew(square_size);
		j = 0;
		while (j < square_size)
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}

void		print_square(char **square)
{
	int		i;

	i = 0;
	while (square[i])
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}
