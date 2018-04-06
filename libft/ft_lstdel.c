/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:14:20 by akabbouc          #+#    #+#             */
/*   Updated: 2016/11/13 02:33:10 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	if (alst && del)
	{
		while (*alst)
		{
			new = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = new;
		}
		(*alst) = NULL;
	}
}
