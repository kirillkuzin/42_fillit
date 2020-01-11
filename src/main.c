/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/11 23:52:06 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			amount_of_tetrominoes;
	// Найти новое место для сохранения размера мапы
	size_t		square_size;
	t_list		**tetrominoes;
	char		**square;

	amount_of_tetrominoes = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	tetrominoes = read_tetrominoes(fd, &amount_of_tetrominoes);
	close(fd);
	square_size = get_square_size(amount_of_tetrominoes);
	square = new_square(square_size);
	while (!(square = algorithm(tetrominoes, square)))
		square = new_square(++square_size);
	print_square(square);
	return (0);
}
