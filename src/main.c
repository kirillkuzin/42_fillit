/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/25 23:07:51 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(int argc, char **argv)
{
	int			amount;
	size_t		square_size;
	t_list		**tetri;
	char		**square;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	else
	{
		if ((tetri = read_tetri(open(argv[1], O_RDONLY), &amount)) == NULL)
		{
			ft_putstr("error\n");
			return (1);
		}
		ft_lstiter(*tetri, write_tetromino);
		square_size = get_square_size(amount);
		square = new_square(square_size);
		while (!(square = algorithm(*tetri, square)))
			square = new_square(++square_size);
		print_square(square);
		return (0);
	}
}
