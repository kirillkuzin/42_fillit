/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:13:05 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/18 22:56:37 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*strcp;

	i = 0;
	if (f && s)
	{
		len = ft_strlen((char*)(s));
		strcp = (char*)malloc(sizeof(char) * (len + 1));
		if (strcp != NULL)
		{
			strcp[len] = '\0';
			while (s[i])
			{
				strcp[i] = f(i, s[i]);
				i++;
			}
			return (strcp);
		}
	}
	return (NULL);
}
