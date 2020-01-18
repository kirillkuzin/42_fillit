/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:06:04 by ggeordi           #+#    #+#             */
/*   Updated: 2019/09/23 20:25:56 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*newlst_first;
	t_list	*tmp;

	if (lst && f)
	{
		newlst_first = f(lst);
		if (newlst_first == NULL)
			return (NULL);
		lst = lst->next;
		newlst = newlst_first;
		while (lst)
		{
			tmp = f(lst);
			if (tmp == NULL)
				return (NULL);
			newlst->next = tmp;
			newlst = tmp;
			lst = lst->next;
		}
		return (newlst_first);
	}
	return (NULL);
}
