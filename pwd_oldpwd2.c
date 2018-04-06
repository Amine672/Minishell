/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_oldpwd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:49:32 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:02:34 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	swap_(t_env *tmp, char *pwd)
{
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "OLDPWD") == 0)
		{
			ft_memdel((void **)&tmp->value);
			tmp->value = ft_strdup(pwd);
			ft_memdel((void **)&tmp->path);
			ft_memdel((void **)&pwd);
			pwd = ft_strjoin(tmp->name, "=");
			tmp->path = ft_strjoin(pwd, tmp->value);
			ft_memdel((void **)&pwd);
		}
		tmp = tmp->next;
	}
}

void	swap(t_env **e, t_env *tmp, char *pwd, char *oldpwd)
{
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "PWD") == 0)
		{
			ft_memdel((void **)&tmp->value);
			tmp->value = ft_strdup(oldpwd);
			ft_memdel((void **)&tmp->path);
			ft_memdel((void **)&oldpwd);
			oldpwd = ft_strjoin(tmp->name, "=");
			tmp->path = ft_strjoin(oldpwd, tmp->value);
			ft_memdel((void **)&oldpwd);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = *e;
	swap_(tmp, pwd);
}

int		pwd_error(char *path)
{
	struct stat filestat;
	int			i;
	int			k;

	stat(path, &filestat);
	i = 0;
	k = 0;
	i = access(path, F_OK);
	i = access(path, R_OK);
	if (!(S_ISDIR(filestat.st_mode)))
		return (1);
	else if (k == -1)
		return (1);
	else if (i == -1)
		return (1);
	return (0);
}

char	*oldpwd_path(char *cwd)
{
	char	*tmp;
	char	*final;

	tmp = NULL;
	final = NULL;
	tmp = ft_strdup("OLDPWD=");
	final = ft_strjoin(tmp, cwd);
	free(tmp);
	return (final);
}
