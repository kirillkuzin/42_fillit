/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbert <malbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:32:18 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/18 14:39:17 by malbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int			line_is_valid(char *line, int i)
{
	if (line && i)
		return (1);
	return (0);
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
	char			buf[22];

	j = 0;
	while ((i = read(fd, buf, 21)))
	{
		buf[i] = '\0';
		if (i == -1 || !line_is_valid(&buf[0], i) || !(tetromino = new_tetromino(&buf[0], 'A' + j)))
		{
			ft_lstdel(tetrominoes, free_tetromino);
			return (NULL);
		}
		tetrominoes = save_tetromino(tetromino);
		(*amount_of_tetrominoes)++;
	}
	return (tetrominoes);
}
