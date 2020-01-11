/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirillkuzin <kirillkuzin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/16 17:14:31 by kirillkuzin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			amount_of_tetrominoes;
	t_list		**tetrominoes;
	char		**square;

	amount_of_tetrominoes = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	tetrominoes = read_tetrominoes(fd, &amount_of_tetrominoes);
	close(fd);
	ft_lstiter(*tetrominoes, write_tetromino);
	square = new_square(amount_of_tetrominoes * 2);
	print_square(square);
	return (0);
}
