/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:11:06 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/11 18:16:00 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str != NULL)
		ft_strcpy(str, s1);
	return (str);
}
