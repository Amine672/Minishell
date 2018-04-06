/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 00:27:26 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/15 00:39:05 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			len_list(t_env *e)
{
	size_t	i;
	t_env	*tmp;

	i = 0;
	tmp = e;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void		minishell_loop(t_tools *t, char **env)
{
	if (t->i != 1 && !t->k && !t->j && !t->c && !t->o && t->av)
		ft_putendl("command not found");
	if (t->i != 1)
		tools3(t->env, t->av, t->tmp);
	else
		minishell__(t, env);
}

void		print_list(t_env *e)
{
	while (e)
	{
		ft_putendl(e->path);
		e = e->next;
	}
}

void		setenv_pwd_(t_env *e, char *cwd)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (e)
	{
		if (e->name && ft_strcmp(e->name, "PWD") == 0)
		{
			tmp2 = ft_strdup(e->value);
			ft_memdel((void **)&(e->value));
			e->value = ft_strdup(cwd);
			if (!e->value)
				e->value = ft_strdup(tmp2);
			tmp = ft_strjoin(e->name, "=");
			ft_memdel((void **)&(e->path));
			e->path = ft_strjoin(tmp, e->value);
			ft_memdel((void **)&(tmp));
			ft_memdel((void **)&(tmp2));
			return ;
		}
		e = e->next;
	}
}

void		print_prompt(void)
{
	char	*cwd;
	char	toto[1024];
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	cwd = getcwd(toto, 1024);
	if (cwd)
	{
		if (ft_strcmp(cwd, "/") == 0)
			display_color_prompt("/ ");
		else if (ft_strcmp(cwd, "/private/tmp") == 0)
			display_color_prompt("/tmp ");
		else
		{
			split = ft_strsplit(cwd, '/');
			while (split[i])
				i++;
			display_color_prompt(split[i - 1]);
			ft_putchar(' ');
			ft_tabfree(split);
		}
	}
}
