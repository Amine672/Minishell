/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:28:15 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 18:46:38 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		tools_free(char *name, char *value, char *path, t_env *tmp)
{
	free(name);
	free(value);
	free(path);
	free(tmp);
}

void		tools3(char **env, char **av, char *tmp)
{
	ft_memdel((void **)&(tmp));
	ft_tabfree(env);
	ft_tabfree(av);
}

void		tools4(t_env *tmp, char *split)
{
	ft_memdel((void **)&tmp->value);
	tmp->value = ft_strdup(split);
}

void		tools5(t_env *tmp)
{
	ft_memdel((void **)&tmp->value);
	tmp->value = ft_strdup("");
	ft_memdel((void **)&tmp->path);
	tmp->path = tools_join(tmp->name, tmp->value);
}

int			tools6(char *av)
{
	if (!ft_strchr(av, '='))
	{
		ft_putendl("invalid argument");
		return (1);
	}
	return (0);
}
