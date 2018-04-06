/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:35:22 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 18:42:54 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			cd_tools(char *path, t_env *e)
{
	if (path && ft_strcmp(path, "/") == 0)
	{
		chdir_err(path);
		return (1);
	}
	else if (path && ft_strcmp(path, "/tmp") == 0)
	{
		chdir_err(path);
		return (1);
	}
	else if (path && ft_strcmp(path, "~") == 0)
	{
		while (e)
		{
			if (ft_strcmp(e->name, "HOME") == 0)
			{
				path = e->value;
				chdir(path);
				return (1);
			}
			e = e->next;
		}
	}
	return (0);
}

int			cd_tools2(char *path)
{
	if (path != NULL)
	{
		chdir_err(path);
		return (1);
	}
	return (0);
}

char		*cd_tools3(t_env *e)
{
	char	*tmp;

	tmp = NULL;
	while (e)
	{
		if (ft_strcmp(e->name, "HOME") == 0)
			tmp = e->value;
		e = e->next;
	}
	return (tmp);
}

char		*tools_join(char *name, char *value)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = NULL;
	tmp = ft_strjoin(name, "=");
	tmp2 = ft_strjoin(tmp, value);
	ft_memdel((void **)&(tmp));
	return (tmp2);
}
