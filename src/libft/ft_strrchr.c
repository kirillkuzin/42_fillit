/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:11:45 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/13 21:39:39 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*c_pos;
	char	*s_pos;

	c_pos = ft_strchr(s, c);
	if (c_pos != NULL && *c_pos != '\0')
	{
		s_pos = c_pos;
		c_pos = ft_strrchr(c_pos + 1, c);
		if (c_pos == NULL)
			return (s_pos);
	}
	return (c_pos);
}
