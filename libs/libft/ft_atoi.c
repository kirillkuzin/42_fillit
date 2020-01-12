/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:51:26 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/22 19:15:09 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char static	*is_space(char *s)
{
	while (*s == '\n' || *s == '\v' || *s == '\t' || \
				*s == '\r' || *s == '\f' || *s == ' ')
		s++;
	return (s);
}

int			ft_atoi(const char *str)
{
	char					*s;
	unsigned long long		result;
	int						negative;

	s = (char*)(str);
	negative = 1;
	result = 0;
	s = is_space(s);
	if (*s == '-')
		negative = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - 48);
		if (negative == 1 && result > 9223372036854775807)
			return (-1);
		if (negative == -1 && result > 9223372036854775808U)
			return (0);
		s++;
	}
	result = (int)result * negative;
	return (result);
}
