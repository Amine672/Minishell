/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 00:13:28 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/14 20:49:20 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			get_cd_(t_env *e)
{
	char	*path;

	path = NULL;
	while (e)
	{
		if (e->name && ft_strcmp(e->name, "OLDPWD") == 0)
		{
			path = ft_strdup(e->value);
			chdir(path);
			ft_memdel((void **)&path);
			return (1);
		}
		e = e->next;
	}
	return (0);
}

int			get_cd(char *path, char *av, t_env *e)
{
	t_env	*tmp2;
	char	toto[1024];
	char	*cwd;

	cwd = getcwd(toto, 1024);
	if (path && ft_strcmp(path, "-") == 0 && get_cd_(e))
		return (1);
	if (cd_tools(path, e))
		return (1);
	tmp2 = e;
	cwd = ft_strjoin(cwd, "/");
	path = ft_strjoin(cwd, path);
	ft_memdel((void **)&cwd);
	if (av && ft_strcmp(av, "cd") == 0)
	{
		if (cd_tools2(path))
			return (1);
		else
		{
			path = cd_tools3(tmp2);
			chdir(path);
			return (1);
		}
	}
	return (0);
}

int			ft_env(char *av, t_env *e, char *av1)
{
	t_env	*tmp;

	tmp = e;
	if (ft_strcmp(av, "env") == 0)
	{
		if (av1 && ft_strcmp(av1, "-i") == 1)
			return (0);
		if (av1)
			while (tmp)
			{
				if (ft_strcmp(tmp->name, "PATH") == 0)
				{
					if (ft_strcmp(av1, "ls") == 0)
						e->bin = ft_strdup("/bin/ls");
					else if (ft_strcmp(av1, "pwd") == 0)
						e->bin = ft_strdup("/bin/pwd");
					return (2);
				}
				tmp = tmp->next;
			}
		else
			print_list(tmp);
		return (1);
	}
	return (0);
}

int			ft_echo(char **av)
{
	int		i;

	i = 0;
	if (av[0] && ft_strcmp(av[0], "echo") == 0)
	{
		if (av[1] && ft_strcmp(av[1], "-n") == 0)
		{
			i = 1;
			while (av[++i])
				echo_display(av[i]);
			return (1);
		}
		else
		{
			while (av[++i])
				echo_display(av[i]);
			ft_putchar('\n');
			return (1);
		}
	}
	return (0);
}

char		*path_(char *path, char *tmp, char *line, char *split)
{
	tmp = ft_strjoin(split, "/");
	path = ft_strjoin(tmp, line);
	ft_memdel((void **)&tmp);
	return (path);
}
