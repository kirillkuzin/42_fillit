/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/10 23:51:35 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(int argc, char **argv)
{
	int			amount;
	size_t		square_size;
	t_list		*tetri;
	char		**square;

	amount = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	else
	{
		if ((tetri = read_tetri(open(argv[1], O_RDONLY), &amount)) == NULL)
		{
			ft_putstr("error\n");
			exit(1);
		}
		square_size = get_square_size(amount);
		if (!(square = new_square(square_size)))
			exit(1);
		while (!(square = algorithm(tetri, square, 1)))
		{
			free_square(square, square_size);
			if (!(square = new_square(++square_size)))
				exit(1);
		}
		print_square(square);
		exit(0);
	}
}
