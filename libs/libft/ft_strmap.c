/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:43:51 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/18 22:54:19 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strcp;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (f && s)
	{
		len = ft_strlen((char*)(s));
		strcp = (char*)malloc(sizeof(char) * (len + 1));
		if (strcp != NULL)
		{
			strcp[len] = '\0';
			while (s[i])
			{
				strcp[i] = f(s[i]);
				i++;
			}
			return (strcp);
		}
	}
	return (NULL);
}
