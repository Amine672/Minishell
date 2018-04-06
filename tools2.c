/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 19:22:20 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 18:46:26 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			tools(t_env **e, char *av0, char *av1)
{
	int		i;
	t_env	*tmp;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	tmp = *e;
	if ((!av0 && !av1) || !av0 || !av1)
		return (0);
	if (update_value(e, av0, av1, tmp))
		return (1);
	if (setenv_list(e, av0, av1))
		return (1);
	if (unsetenv_list(e, av0, av1))
		return (1);
	return (0);
}

t_tools		*init_tools(char **av, t_env *e, char **env)
{
	t_tools	*t;

	if (!(t = (t_tools *)malloc(sizeof(t_tools))))
		exit(1);
	t->i = -1;
	t->o = 0;
	t->c = 0;
	t->k = 0;
	t->av = av;
	t->tmp = NULL;
	t->e = NULL;
	t->tmp2 = e;
	t->j = 0;
	t->line = NULL;
	t->env = env;
	return (t);
}

void		ft_tabfree(char **tab)
{
	int		i;

	i = 0;
	if (!tab || !*tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void		free_listee(t_env **e)
{
	t_env	*tmp;
	t_env	*next;

	tmp = *e;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->value);
		free(tmp->name);
		free(tmp->path);
		free(tmp);
		tmp = next;
	}
	*e = NULL;
}
