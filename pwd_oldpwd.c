/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_oldpwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:10:39 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:01:33 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*pwd_home(t_env *tmp)
{
	char	*final;
	char	*tmp2;
	char	*path;

	final = NULL;
	path = NULL;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "HOME") == 0)
			path = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	tmp2 = ft_strdup("PWD=");
	final = ft_strjoin(tmp2, path);
	free(tmp2);
	free(path);
	return (final);
}

int		pwd_(t_env **e, t_env *tmp, char *av1)
{
	char	*final;

	final = NULL;
	if (av1 && ft_strcmp(av1, "/") == 0)
		final = ft_strdup("PWD=/");
	if (av1 && ft_strcmp(av1, "/tmp") == 0)
		final = ft_strdup("PWD=/tmp");
	if (av1 && ft_strcmp(av1, "/bin") == 0)
		final = ft_strdup("PWD=/bin");
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (final)
	{
		creat_maillon(e, final, tmp);
		free(final);
		return (1);
	}
	return (0);
}

int		pwd(t_env **e, t_env *tmp, char *cwd, char *av1)
{
	char	*path;
	char	*tmp2;

	tmp2 = NULL;
	path = NULL;
	path = ft_strdup("PWD=");
	tmp2 = ft_strjoin(path, cwd);
	ft_memdel((void **)&path);
	path = ft_strjoin(tmp2, "/");
	ft_memdel((void **)&tmp2);
	tmp2 = ft_strjoin(path, av1);
	free(path);
	while (tmp && tmp->next)
		tmp = tmp->next;
	creat_maillon(e, tmp2, tmp);
	ft_memdel((void **)&tmp2);
	return (1);
}

int		pwd_home_(t_env **e, t_env *tmp, char *av1)
{
	char	*path;

	path = NULL;
	if (!av1)
	{
		path = pwd_home(tmp);
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (path)
			creat_maillon(e, path, tmp);
		free(path);
		return (1);
	}
	return (0);
}

int		pwd_back(t_env **e, t_env *tmp, char *av1, char *cwd)
{
	char	*path;

	path = NULL;
	if (av1 && ft_strcmp(av1, "..") == 0)
	{
		path = cd_pwd(cwd);
		while (tmp && tmp->next)
			tmp = tmp->next;
		creat_maillon(e, path, tmp);
		free(path);
		return (1);
	}
	return (0);
}
