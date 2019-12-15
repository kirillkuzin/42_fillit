/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:56:32 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/22 19:36:39 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		split_count(char const *s, char c)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	paste_word(char const *s, char c, char **arr)
{
	size_t		i;
	size_t		f;
	size_t		j;

	f = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		f = i;
		while (s[i] != c && s[i])
			i++;
		if (i == f)
			break ;
		arr[j] = (char*)malloc(i - f + 1);
		if (arr[j] == NULL)
			return (0);
		ft_strncpy(arr[j], &s[f], i - f);
		arr[j][i - f] = '\0';
		j++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		j;
	int			words;

	j = 0;
	words = split_count(s, c);
	arr = (char**)malloc(sizeof(char*) * (words + 1));
	if (arr == NULL)
		return (NULL);
	if (words > 0)
	{
		j = paste_word(s, c, arr);
		if (j == 0)
			return (NULL);
	}
	arr[j] = (char*)malloc(sizeof(char));
	if (arr[j] == NULL)
		return (NULL);
	arr[j] = NULL;
	return (arr);
}
