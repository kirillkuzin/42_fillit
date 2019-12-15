/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:23:48 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/22 19:25:20 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	if (!dst && !src && len > 0)
		return (dst);
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	if (str2 < str1)
	{
		while (++i <= len)
			str1[len - i] = str2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(str1++) = *(str2++);
	}
	return (dst);
}
