/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:49:34 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/22 19:36:15 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_char_count(int n)
{
	int		f;

	f = 1;
	while (n >= 10)
	{
		n /= 10;
		f++;
	}
	return (f);
}

static int	is_negative(int n, int *negative)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			*negative = 2;
			n = 147483648;
		}
		else
		{
			*negative = 1;
			n = -n;
		}
	}
	return (n);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			negative;

	negative = 0;
	n = is_negative(n, &negative);
	i = get_char_count(n);
	str = (char*)malloc(sizeof(char) * (i + 1 + negative));
	if (str == NULL)
		return (NULL);
	str[i + negative] = '\0';
	if (negative)
		str[0] = '-';
	if (negative == 2)
		str[1] = 2 + '0';
	while (i + negative > negative)
	{
		str[i + negative - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
