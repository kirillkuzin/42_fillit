/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:04:23 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/18 23:14:16 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str = (char*)malloc(len_s1 + len_s2 + 1);
		if (str != NULL)
		{
			str[len_s1 + len_s2] = '\0';
			ft_strcpy(str, s1);
			ft_strcpy(&str[len_s1], s2);
			return (str);
		}
	}
	return (NULL);
}
