/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:00:18 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/18 23:04:13 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (s && len)
	{
		substr = (char*)malloc(len + 1);
		if (substr != NULL)
		{
			substr[len] = '\0';
			while (i < len)
			{
				substr[i] = s[start + i];
				i++;
			}
			return (substr);
		}
	}
	return (NULL);
}
