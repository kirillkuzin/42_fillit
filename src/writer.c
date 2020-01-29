/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:23:16 by ggeordi           #+#    #+#             */
/*   Updated: 2020/01/29 23:29:16 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void		write_tetromino(t_list *elem)
{
	int				i;
	t_tetromino		*tetromino;

	i = 0;
	tetromino = elem->content;
	while (i < 4)
	{
		printf("%s\n", tetromino->body[i]);
		i++;
	}
	printf("-------------------\n");
}
