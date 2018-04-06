/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:49:56 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/12 03:36:51 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	if (lst && f)
	{
		list = f(lst);
		tmp = list;
		while (lst->next)
		{
			tmp->next = f(lst->next);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (list);
}
