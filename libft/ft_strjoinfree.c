/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:30:29 by ggeordi           #+#    #+#             */
/*   Updated: 2019/11/25 14:30:30 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char *s;

	s = NULL;
	if (s1 && s2)
	{
		s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!s)
			return (NULL);
		ft_strcpy(s, s1);
		ft_strcat(s, s2);
		ft_strdel(&s1);
	}
	return (s);
}
