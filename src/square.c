/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:43:51 by kirillkuzin       #+#    #+#             */
/*   Updated: 2020/01/18 14:32:29 by malbert          ###   ########.fr       */
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
