/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:32:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/29 23:51:28 by ggeordi          ###   ########.fr       */
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

t_list		**save_tetromino(t_tetromino *tetromino)
{
	static t_list	*tetrominoes;
	t_list			*new_tetromino;

	if (tetrominoes == NULL)
	{
		if (!(tetrominoes = ft_lstnew(tetromino, sizeof(tetromino))))
			return (NULL);
	}
	else
	{
		if (!(new_tetromino = ft_lstnew(tetromino, sizeof(tetromino))))
			return (NULL);
		ft_lstadd(&tetrominoes, new_tetromino);
	}
	tetromino = tetrominoes->content;
	return (&tetrominoes);
}

t_list		**read_tetri(int fd, int *amount_of_tetrominoes)
{
	int				i;
	t_tetromino		*tetromino;
	t_list			**tetrominoes;
	char			buf[21];

	tetrominoes = NULL;
	while ((i = read(fd, &buf[0], 21)) >= 20)
	{
		if (!(line_is_valid(&buf[0], i))
		|| !(tetromino = new_tetromino(&buf[0], 'A' + (*amount_of_tetrominoes))))
		{
			if (tetrominoes)
				ft_lstdel(tetrominoes, free_tetromino);
			return (NULL);
		}
		if (!(tetrominoes = save_tetromino(tetromino)))
			return (NULL);
		(*amount_of_tetrominoes)++;
	}
	if (i == -1 || i > 0)
	{
		if (tetrominoes)
			ft_lstdel(tetrominoes, free_tetromino);
		return (NULL);
	}
	ft_lstrev(tetrominoes);
	return (tetrominoes);
}
