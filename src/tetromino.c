/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:15:27 by ggeordi           #+#    #+#             */
/*   Updated: 2019/12/15 21:14:58 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*new_tetromino()
{
	t_tetromino		*tetromino;
	int				i;

	i = 0;
	if (!(tetromino = (t_tetromino*)malloc(sizeof(t_tetromino))))
		return (NULL);
	tetromino->body = (char**)malloc(sizeof(char*) * 5);
	while (i < 4)
	{
		tetromino->body[i] = (char*)malloc(sizeof(char) * 5);
		tetromino->body[i][4] = '\0';
		i++;
	}
	return (tetromino);
}

void		free_tetromino(void *tetromino, size_t tetromino_size)
{

}
