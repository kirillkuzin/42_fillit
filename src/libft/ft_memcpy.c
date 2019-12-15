/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:03:25 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/22 14:23:03 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	if (!destination && !source)
	{
		return (NULL);
	}
	dst = (unsigned char*)(destination);
	src = (unsigned char*)(source);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (destination);
}
