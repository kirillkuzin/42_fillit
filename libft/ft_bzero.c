/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:20:06 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/10 23:28:37 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		dst[i] = (unsigned char)(0);
		i++;
	}
}
