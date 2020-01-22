/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/22 21:09:01 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			amount_of_tetrominoes;
	// size_t		square_size;
	t_list		**tetrominoes;
	// char		**square;

	amount_of_tetrominoes = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		tetrominoes = read_tetrominoes(fd, &amount_of_tetrominoes);
		ft_lstiter(*tetrominoes, write_tetromino);
		close(fd);
		if(tetrominoes == NULL)
		{
			ft_putstr("error\n");
			return (1);
		}
		// square_size = get_square_size(amount_of_tetrominoes);
		// square_size = 4;
		// square = new_square(square_size);
		// while (!(square = algorithm(*tetrominoes, square)))
		// {
		// 	square = new_square(++square_size);
		// 	// printf("%zu", square_size);
		// }
		// print_square(square);
		return (0);
	}
}
