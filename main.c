/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:01:17 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 17:04:08 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int		error_cd_pwd(char *cwd, char *av1, int i, int k)
{
	char		*path;
	char		*tmp;
	struct stat filestat;

	path = NULL;
	tmp = NULL;
	tmp = ft_strjoin(cwd, "/");
	path = ft_strjoin(tmp, av1);
	ft_memdel((void **)&tmp);
	stat(path, &filestat);
	i = access(path, F_OK);
	k = access(path, R_OK);
	if (!(S_ISDIR(filestat.st_mode)))
	{
		ft_memdel((void **)&path);
		return (1);
	}
	if (k == -1 || i == -1)
	{
		ft_memdel((void **)&path);
		return (1);
	}
	if (path)
		ft_memdel((void **)&path);
	return (0);
}

void	pwd_oldpwd(t_env **e, t_env *tmp, char *av1, char *av)
{
	char	toto[1024];
	int		i;
	int		k;
	char	*cwd;

	cwd = NULL;
	i = 0;
	k = 0;
	cwd = getcwd(toto, 1024);
	if (av && ft_strcmp(av, "cd") == 0)
	{
		if (error_cd_pwd(cwd, av1, i, k) || (av1 && ft_strcmp(av1, "-") == 0))
			return ;
		else
			setenv_pwd__(e, tmp, cwd, av1);
	}
}

void	setenv__pwd(t_env **e, t_env *tmp, char *av1, char *cwd)
{
	if (pwd_(e, tmp, av1))
		return ;
	if (pwd_back(e, tmp, av1, cwd))
		return ;
	if (pwd_home_(e, tmp, av1))
		return ;
	if (pwd(e, tmp, cwd, av1))
		return ;
}

char	*cd_pwd(char *cwd)
{
	char	*tmp;
	char	*tmp2;
	char	*final;
	int		i;

	final = NULL;
	tmp = NULL;
	tmp2 = NULL;
	i = ft_strlen(cwd);
	tmp = ft_strdup("PWD=");
	while (cwd[i] != '/')
		i--;
	tmp2 = ft_strsub(cwd, 0, i);
	final = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp);
	return (final);
}

int		main(int ac, char **av, char **env)
{
	t_env		*e;
	t_tools		*t;
	extern char **environ;
	char		*cwd;
	char		toto[1024];

	ac = 0;
	cwd = NULL;
	av = NULL;
	env = NULL;
	e = NULL;
	t = init_tools(av, e, env);
	while (environ && environ[++t->i])
		add_list(&t->e, environ[t->i]);
	minishell(t, cwd, toto);
	return (0);
}
