/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:38:23 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:03:35 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			parser_stat__(char *path, t_env *e, char **split, char *line)
{
	int			i;
	char		*tmp2;
	struct stat filestat;

	i = 0;
	tmp2 = NULL;
	while (split[i])
	{
		path = path_(path, tmp2, line, split[i]);
		if (stat(path, &filestat) == 0)
		{
			e->bin = ft_strdup(path);
			ft_memdel((void **)&path);
			ft_tabfree(split);
			if (!error_bin(e->bin))
				return (0);
			return (1);
		}
		ft_memdel((void **)&path);
		i++;
	}
	ft_tabfree(split);
	return (0);
}

int			parser_stat_(t_env *e, char *path, char *line)
{
	t_env		*tmp;
	char		**split;

	split = NULL;
	tmp = e;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, "PATH") == 0)
		{
			split = ft_strsplit(tmp->value, ':');
			if (!parser_stat__(path, e, split, line))
				return (0);
			else
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			parser_stat(char *line, char *check, t_env *e)
{
	struct stat filestat;
	int			i;
	char		*path;

	i = 0;
	path = NULL;
	if (stat(check, &filestat) == 0)
		return (1);
	if (stat(line, &filestat) == 0)
	{
		e->bin = ft_strdup(line);
		return (1);
	}
	i = parser_stat_(e, path, line);
	if (i == 1)
		return (1);
	return (0);
}

int			update_value(t_env **e, char *check, char *av, t_env *tmp)
{
	char	**split;

	tmp = *e;
	split = NULL;
	split = ft_strsplit(av, '=');
	if (ft_strcmp(check, "setenv") == 0)
	{
		while (tmp)
		{
			if (split && split[0] && ft_strcmp(split[0], tmp->name) == 0)
			{
				if (split[1] == NULL)
					tools5(tmp);
				else
					tools4(tmp, split[1]);
				ft_memdel((void **)&tmp->path);
				tmp->path = tools_join(tmp->name, tmp->value);
				ft_tabfree(split);
				return (1);
			}
			tmp = tmp->next;
		}
	}
	ft_tabfree(split);
	return (0);
}

char		*parser(char *line, char **env)
{
	char		*tmp;
	struct stat	filestat;

	if (!env)
	{
		tmp = NULL;
		if (stat(line, &filestat) == 0)
			tmp = ft_strdup(line);
		return (tmp);
	}
	return (0);
}
