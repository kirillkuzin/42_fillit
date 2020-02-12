/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/12 23:41:03 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char			**solve(t_list *tetri, int amount)
{
	size_t		square_size;
	char		**square;

	square_size = get_square_size(amount);
	if (!(square = new_square(square_size)))
		return (NULL);
	while (!(square = algorithm(tetri, square, 1)))
	{
		free_square(square, square_size);
		if (!(square = new_square(++square_size)))
			return (NULL);
	}
	return (square);
}

int				main(int argc, char **argv)
{
	int			amount;
	char		**square;
	t_list		*tetri;

	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	else
	{
		if (!(tetri = read_tetri(open(argv[1], O_RDONLY), &amount)))
		{
			ft_putstr("error\n");
			exit(1);
		}
		if (!(square = solve(tetri, amount)))
			exit(1);
		print_square(square);
		exit(0);
	}
}
