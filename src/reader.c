/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:32:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/12 23:40:41 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			tetri_valid(char *line)
{
	int i;
	int counter;
	int	counter_sharps;

	counter = 0;
	counter_sharps = 0;
	i = 0;
	while (i < 20)
	{
		if (line[i] == '#')
		{
			if ((i + 1) < 20 && line[i + 1] == '#')
				counter++;
			if ((i - 1) >= 0 && line[i - 1] == '#')
				counter++;
			if ((i + 5) < 20 && line[i + 5] == '#')
				counter++;
			if ((i - 5) >= 0 && line[i - 5] == '#')
				counter++;
			counter_sharps++;
		}
		i++;
	}
	return (counter == 6 || counter == 8);
}

int			line_is_valid(char *line, int counter)
{
	int	height;
	int i;

	height = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(line[i] == '#' || line[i] == '.'))
				return (0);
		}
		else if (line[i] != '\n')
			return (0);
		else if (line[i] == '\n')
			height++;
		i++;
	}
	if (height != 4)
		return (0);
	if (counter == 21 && line[20] != '\n')
		return (0);
	if (!(tetri_valid(line)))
		return (0);
	return (1);
}

t_list		*save_tetromino(t_list *tetrominoes, int *amount_of_tetrominoes,
							char *buf, int i)
{
	t_list				*next_tetrimino;
	t_tetromino			*tetromino;

	if (!(line_is_valid(buf, i))
	|| *(amount_of_tetrominoes) == 26
	|| !(tetromino = new_tetromino(
			buf, 'A' + (*amount_of_tetrominoes))))
	{
		if (tetrominoes)
			ft_lstdel(&tetrominoes, free_tetromino);
		return (NULL);
	}
	next_tetrimino = tetrominoes;
	if (!(tetrominoes = (t_list*)malloc(sizeof(t_list))))
	{
		free_tetromino(tetromino, sizeof(tetromino));
		ft_lstdel(&next_tetrimino, free_tetromino);
		return (NULL);
	}
	tetrominoes->content = tetromino;
	tetrominoes->content_size = sizeof(tetromino);
	tetrominoes->next = next_tetrimino;
	(*amount_of_tetrominoes)++;
	return (tetrominoes);
}

t_list		*read_tetri(int fd, int *amount_of_tetrominoes)
{
	int				i;
	int				last_i;
	t_list			*tetrominoes;
	char			buf[21];

	tetrominoes = NULL;
	last_i = 0;
	while ((i = read(fd, &buf[0], 21)) >= 20)
	{
		if (!(tetrominoes = save_tetromino(tetrominoes,
		amount_of_tetrominoes, &buf[0], i)))
			return (NULL);
		last_i = i;
	}
	if (i == -1 || i > 0 || last_i == 0 || last_i == 21)
	{
		ft_lstdel(&tetrominoes, free_tetromino);
		return (NULL);
	}
	ft_lstrev(&tetrominoes);
	return (tetrominoes);
}
