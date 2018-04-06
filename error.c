/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:16:17 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:08:42 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			error_bin(char *ebin)
{
	if (ebin && ft_strcmp(ebin, "/usr/bin/env") == 0)
	{
		free(ebin);
		return (0);
	}
	else if (ebin && ft_strcmp(ebin, "/usr/bin/cd") == 0)
	{
		free(ebin);
		return (0);
	}
	return (1);
}

void		display_error(char *path)
{
	struct stat filestat;
	int			i;
	int			k;
	char		*tmp;

	i = 0;
	k = 0;
	tmp = NULL;
	stat(path, &filestat);
	i = access(path, F_OK);
	k = access(path, R_OK);
	path = error_cd(path);
	if (!S_ISDIR(filestat.st_mode) && i == 0 && k == 0)
		ft_putstr("cd: not a directory: ");
	else if (k == -1 && i == 0)
		ft_putstr("cd: permission denied: ");
	else if (i == -1)
		ft_putstr("cd: no such file or directory: ");
	if (!S_ISDIR(filestat.st_mode) && i == 0 && k == 0)
		ft_putendl(path);
	else if (k == -1 && i == 0)
		ft_putendl(path);
	else if (i == -1)
		ft_putendl(path);
	ft_memdel((void **)&path);
}

void		chdir_err(char *path)
{
	chdir(path);
	display_error(path);
	if (ft_strncmp(path, "/", 1) == 0)
		return ;
}

void		creat_maillon(t_env **e, char *av, t_env *tmp)
{
	if (*e)
		tmp->next = new_list(av);
	else
		(*e) = new_list(av);
}

char		*error_cd(char *path)
{
	char	**split;
	char	*tmp;
	int		i;

	split = NULL;
	tmp = NULL;
	i = 0;
	if (ft_strlen(path) == 1)
		if (ft_strncmp(path, "/", 1) == 0)
			return (path);
	split = ft_strsplit(path, '/');
	ft_memdel((void **)&path);
	while (split[i])
		i++;
	tmp = ft_strdup(split[i - 1]);
	ft_tabfree(split);
	return (tmp);
}
