/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:23:48 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/13 17:02:28 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	display_list(t_env *e)
{
	t_env	*tmp;

	if (!e)
		return ;
	tmp = e;
	while (tmp)
	{
		ft_putendl(tmp->path);
		tmp = tmp->next;
	}
}

void	display_prompt(void)
{
	print_prompt();
	ft_putstr(C_CYAN);
	ft_putstr("$> ");
	ft_putstr(C_RES);
}

void	echo_display(char *av)
{
	ft_putstr(av);
	ft_putchar(' ');
}

void	display_color_prompt(char *str)
{
	ft_putstr(C_BLUE);
	ft_putstr(str);
	ft_putstr(C_RES);
}

void	setup_int(t_tools *t)
{
	t->k = 0;
	t->j = 0;
	t->o = 0;
	t->c = 0;
}
