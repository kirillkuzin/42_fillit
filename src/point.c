/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:29:42 by ggeordi           #+#    #+#             */
/*   Updated: 2020/02/12 22:10:38 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

t_point				*create_point(void)
{
	t_point			*point;

	if (!(point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	point->i = 0;
	point->j = 0;
	return (point);
}

void				free_point(t_point *point)
{
	if (point)
		free(point);
}
