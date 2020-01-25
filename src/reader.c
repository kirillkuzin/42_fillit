/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:32:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/25 23:32:35 by malbert          ###   ########.fr       */
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
		tetrominoes = ft_lstnew(tetromino, sizeof(tetromino));
	else
	{
		new_tetromino = ft_lstnew(tetromino, sizeof(tetromino));
		ft_lstadd(&tetrominoes, new_tetromino);
	}
	return (&tetrominoes);
}

t_list		**read_tetri(int fd, int *amount_of_tetrominoes)
{
	int				i;
	int				j;
	t_tetromino		*tetromino;
	t_list			**tetrominoes;
	char			*buf;

	j = 0;
	buf = ft_strnew(21);
	while ((i = read(fd, buf, 21)) >= 20)
	{
		if (i == -1 || !(line_is_valid(buf, i))
		|| !(tetromino = new_tetromino(buf, 'A' + j)))
		{
			//ft_lstdel(tetrominoes, free_tetromino); крч тут какая то дичь, я не совсем понял почему все ломается, sorry ;(
			return (NULL);
		}
		tetrominoes = save_tetromino(tetromino);
		(*amount_of_tetrominoes)++;
	}
	ft_lstrev(tetrominoes);
	return (tetrominoes);
}
