/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:13:14 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/11 17:57:52 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char*)(destination);
	src = (unsigned char*)(source);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
		if (src[i - 1] == (unsigned char)(c))
			return (&dst[i]);
	}
	return (NULL);
}
