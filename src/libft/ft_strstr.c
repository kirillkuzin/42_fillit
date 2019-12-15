/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:46:17 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/13 22:07:38 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*strcpy;
	char	*substr;

	str = (char*)(haystack);
	if (!*needle)
		return (str);
	while (*str)
	{
		strcpy = str;
		substr = (char*)needle;
		while (*substr)
		{
			if (*str != *substr)
				break ;
			substr++;
			str++;
		}
		if (*substr == '\0')
			return (strcpy);
		str = strcpy;
		str++;
	}
	return (NULL);
}
