/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:26:55 by ggeordi           #+#    #+#             */
/*   Updated: 2019/11/25 14:35:39 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strsub;

	if (len + 1 == 0)
		return (NULL);
	i = 0;
	if (!(strsub = (char *)malloc(sizeof(char) * len + 1)) || !s)
		return (NULL);
	while (i < len)
	{
		strsub[i] = s[i + start];
		i++;
	}
	strsub[i] = '\0';
	ft_strdel(&s);
	return (strsub);
}
