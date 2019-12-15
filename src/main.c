/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:55:46 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/15 17:21:02 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fillit.h"

void	main(int argc, char **argv)
{
	int fd;
	t_list		**tetrominoes;

	fd = open(argv[1], "O_RDONLY");
	if (fd == -1)
		return (-1);
	tetrominoes = read_tetrominoes(fd);
	return (0);
}
