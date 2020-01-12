/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:03:58 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/13 21:10:32 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cc;

	str = (char*)(s);
	cc = (char)(c);
	while (*str)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	if (cc == '\0')
		return (str);
	else
		return (NULL);
}
