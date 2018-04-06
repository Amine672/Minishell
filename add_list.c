/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 16:11:04 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:07:23 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_env		*new_list(char *path)
{
	t_env	*s1;
	int		i;

	if (!(s1 = (t_env*)malloc(sizeof(t_env))))
		return (NULL);
	s1->path = ft_strdup(path);
	i = -1;
	while (path[++i] && path[i] != '=')
		;
	s1->name = ft_strsub(path, 0, i);
	s1->value = ft_strdup(path + ++i);
	s1->next = NULL;
	return (s1);
}

void		add_list(t_env **e, char *path)
{
	t_env	*tmp;

	tmp = *e;
	if (!tmp)
	{
		*e = new_list(path);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_list(path);
}

void		setenv_oldpwd(t_env **e, t_env *tmp, char *cwd)
{
	char	*final;
	t_env	*prev;

	prev = NULL;
	final = NULL;
	tmp = *e;
	final = oldpwd_path(cwd);
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "OLDPWD") == 0)
		{
			unsetenv_list_(&e, &prev, &tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	tmp = *e;
	while (tmp && tmp->next)
		tmp = tmp->next;
	creat_maillon(e, final, tmp);
	free(final);
}

int			swap_pwd_old(t_env **e, t_env *tmp, char *av1)
{
	char	*tmp2;
	char	*tmp3;

	tmp2 = NULL;
	tmp3 = NULL;
	if (av1 && ft_strcmp(av1, "-") == 0)
	{
		while (tmp)
		{
			if (tmp->name && ft_strcmp(tmp->name, "PWD") == 0)
				tmp2 = ft_strdup(tmp->value);
			tmp = tmp->next;
		}
		tmp = *e;
		while (tmp)
		{
			if (tmp->name && ft_strcmp(tmp->name, "OLDPWD") == 0)
				tmp3 = ft_strdup(tmp->value);
			tmp = tmp->next;
		}
		tmp = *e;
		swap(e, tmp, tmp2, tmp3);
	}
	return (0);
}

void		setenv_pwd__(t_env **e, t_env *tmp, char *cwd, char *av1)
{
	t_env	*prev;

	tmp = *e;
	prev = NULL;
	while (tmp)
	{
		if ((av1 && ft_strcmp(av1, ".") == 0))
			return ;
		if (tmp->name && ft_strcmp(tmp->name, "PWD") == 0)
		{
			unsetenv_list_(&e, &prev, &tmp);
			break ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	tmp = *e;
	setenv__pwd(e, tmp, av1, cwd);
	tmp = *e;
	setenv_oldpwd(e, tmp, cwd);
}
