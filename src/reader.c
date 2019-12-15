/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:32:18 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/15 21:15:31 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			line_is_valid(char *line)
{
	return (1);
}

t_list		**save_tetromino(t_tetromino *tetromino)
{
	static t_list	*tetrominoes;
	t_list			*new_tetromino;

	if (tetrominoes == NULL)
		tetrominoes = ft_lstnew(tetromino, sizeof(tetromino));
	else
	{
		new_tetromino = ft_lstnew(tetromino, sizeof(tetromino));
		ft_lstadd(&tetrominoes, new_tetromino);
	}
	return (&tetrominoes);
}

t_list		**read_tetrominoes(int fd, int *amount_of_tetrominoes)
{
	int				i;
	int				j;
	t_tetromino		*tetromino;
	t_list			**tetrominoes;

	j = 0;
	tetromino = new_tetromino();
	while ((i = get_next_line(fd, &(tetromino->body[j]))) != 0)
	{
		if (i == -1 || !(line_is_valid(tetromino->body[j])))
		{
			ft_lstdel(tetrominoes, free_tetromino);
			return (NULL);
		}
		j++;
		if (j == 4)
		{
			tetrominoes = save_tetromino(tetromino);
			(*amount_of_tetrominoes)++;
			i = get_next_line(fd, &(tetromino->body[j]));
			j = 0;
			tetromino = new_tetromino();
		}
	}
	if (j != 0)
		ft_lstdel(tetrominoes, free_tetromino);
	return (tetrominoes);
}
