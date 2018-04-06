/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 14:59:35 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/15 17:10:06 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char		**envi(t_env *e)
{
	int		i;
	t_env	*tmp;
	char	**env;
	char	*tmp2;

	i = 0;
	tmp2 = NULL;
	if (!e)
		return (NULL);
	tmp = e;
	env = (char **)ft_memalloc(sizeof(char *) * (len_list(e) + 1));
	while (tmp)
	{
		if (ft_strcmp(tmp->path, "") == 0)
		{
			if (tmp->next)
				tmp = tmp->next;
		}
		env[i] = ft_strdup((char *)(tmp->path));
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

void		minishell_(t_tools *t)
{
	get_next_line(0, &(t->line));
	t->av = ft_strsplit_tab(t->line);
	ft_memdel((void **)&(t->line));
	if (!t->av)
		return ;
	pwd_oldpwd(&t->e, t->tmp2, t->av[1], t->av[0]);
	if (t->av[0] && !ft_strcmp(t->av[0], "exit"))
	{
		if (t->e)
			free_listee(&t->e);
		exit(1);
	}
	if (t->av[0] && t->av && ft_strcmp(t->av[0], "echo") == 0)
		t->k = ft_echo(t->av);
	if (t->av[0] && ft_strcmp(t->av[0], "cd") == 0)
	{
		t->c = get_cd(t->av[1], t->av[0], t->e);
		if (t->av[1] && ft_strcmp(t->av[1], "-") == 0)
			swap_pwd_old(&t->e, t->e, t->av[1]);
	}
	if (t->av[0] && ft_strcmp(t->av[0], "env") == 0)
		t->o = ft_env(t->av[0], t->e, t->av[1]);
	if (t->av[0])
		t->j = tools(&t->e, t->av[0], t->av[1]);
}

void		minishell__(t_tools *t, char **env)
{
	t->father = fork();
	if (t->father != 0)
		wait(&t->w);
	else
	{
		if (t->k == 0 && t->tmp)
			execve(t->tmp, t->av, env);
		else if (t->k == 0)
			execve(t->e->bin, t->av, t->env);
		else if (!t->av)
			exit(1);
		else
			exit(1);
	}
	t->k = 0;
	ft_tabfree(t->env);
	ft_tabfree(t->av);
	if (t->e && t->e->bin)
		ft_memdel((void **)&(t->e->bin));
	ft_memdel((void **)&(t->tmp));
}

void		minishell(t_tools *t, char *cwd, char *toto)
{
	while (42)
	{
		cwd = getcwd(toto, 1024);
		setup_int(t);
		display_prompt();
		minishell_(t);
		t->env = envi(t->e);
		if (t->av && t->av[0])
		{
			t->tmp = parser(t->av[0], t->env);
			t->i = parser_stat(t->av[0], t->tmp, t->e);
		}
		if (t->o == 2)
		{
			ft_memdel((void **)&t->av[1]);
			if (t->av[2])
				t->av[1] = ft_strdup(t->av[2]);
		}
		minishell_loop(t, t->env);
	}
}
