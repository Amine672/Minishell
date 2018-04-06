/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:23:24 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/14 23:47:18 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		setenv_pwd(t_env *e, char *av)
{
	char	toto[1024];
	char	*cwd;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	cwd = getcwd(toto, 1024);
	if (av && ft_strcmp(av, "cd") == 0)
		setenv_old_pwd(e);
	setenv_pwd_(e, cwd);
}

void		setenv_old_pwd(t_env *e)
{
	t_env	*tmp;
	char	*pwd;
	char	*tmp2;

	tmp = e;
	pwd = NULL;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "PWD") == 0)
			pwd = ft_strdup(tmp->value);
		if (tmp->name && ft_strcmp(tmp->name, "OLDPWD") == 0)
			if (pwd && tmp->value && ft_strcmp(pwd, tmp->value) != 0)
			{
				ft_memdel((void **)&(tmp->value));
				tmp->value = ft_strdup(pwd);
				tmp2 = ft_strjoin(tmp->name, "=");
				ft_memdel((void **)&(tmp->path));
				tmp->path = ft_strjoin(tmp2, tmp->value);
				ft_memdel((void **)&(tmp2));
				ft_memdel((void **)&(pwd));
			}
		tmp = tmp->next;
	}
	ft_memdel((void **)&(pwd));
}

int			setenv_list(t_env **e, char *check, char *av)
{
	t_env	*tmp;
	char	**split;

	if (!ft_strcmp(check, "setenv"))
	{
		if (tools6(av))
			return (1);
	}
	else
		return (0);
	if (!(split = ft_strsplit(av, '=')))
		return (0);
	tmp = *e;
	while (split && tmp && tmp->next && tmp->name && split[0]
			&& ft_strcmp(split[0], tmp->name))
		tmp = tmp->next;
	if (split && split[0] && tmp && !ft_strcmp(split[0], tmp->name))
	{
		ft_tabfree(split);
		return (0);
	}
	creat_maillon(e, av, tmp);
	ft_tabfree(split);
	return (1);
}

int			unsetenv_list_(t_env ***e, t_env **prev, t_env **tmp)
{
	if (!(*prev))
	{
		(**e) = (**e)->next;
		tools_free((*tmp)->name, (*tmp)->value, (*tmp)->path, (*tmp));
	}
	else
	{
		(*prev)->next = (*tmp)->next;
		tools_free((*tmp)->name, (*tmp)->value, (*tmp)->path, (*tmp));
		if ((*prev)->next)
			(*tmp) = (*prev)->next;
	}
	return (1);
}

int			unsetenv_list(t_env **e, char *check, char *av)
{
	t_env	*tmp;
	t_env	*prev;
	int		i;

	tmp = *e;
	prev = NULL;
	i = 0;
	if (ft_strcmp(check, "unsetenv") == 0)
	{
		while (tmp)
		{
			if (av && tmp->name && ft_strcmp(av, tmp->name) == 0)
			{
				unsetenv_list_(&e, &prev, &tmp);
				return (1);
			}
			prev = tmp;
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}
