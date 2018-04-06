/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:00:07 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/30 15:08:04 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include "colors.h"
# include <sys/stat.h>
# include <signal.h>
# include <unistd.h>
# include <sys/param.h>
# include <stdio.h>

typedef struct		s_env
{
	char			*value;
	char			*name;
	int				k;
	char			*path;
	char			*bin;
	struct s_env	*next;
}					t_env;

typedef struct		s_tools
{
	int				o;
	int				c;
	int				i;
	int				k;
	int				w;
	int				j;
	char			*tmp;
	char			**av;
	pid_t			father;
	t_env			*e;
	t_env			*tmp2;
	char			**env;
	char			*line;
}					t_tools;

void				swap(t_env **e, t_env *tmp, char *pwd, char *olwpwd);
int					error_cd_pwd(char *cwd, char *av1, int i, int k);
int					error_bin(char *ebin);
char				*oldpwd_path(char *cwd);
int					pwd_error(char *path);
void				pwd_oldpwd(t_env **e, t_env *tmp, char *av1, char *av);
void				setenv__pwd(t_env **e, t_env *tmp, char *av1, char *cwd);
int					swap_pwd_old(t_env **e, t_env *tmp, char *av1);
void				setenv_oldpwd(t_env **e, t_env *tmp, char *cwd);
int					pwd_(t_env **e, t_env *tmp, char *av1);
int					pwd(t_env **e, t_env *tmp, char *cwd, char *av1);
int					pwd_back(t_env **e, t_env *tmp, char *av1, char *cwd);
int					pwd_home_(t_env **e, t_env *tmp, char *av1);
char				*pwd_home(t_env *tmp);
char				*cd_pwd(char *cwd);
int					unsetenv_list_(t_env ***e, t_env **prev, t_env **tmp);
void				setenv_pwd__(t_env **e, t_env *tmp, char *cwd, char *av1);
void				display_prompt(void);
void				display_color_prompt(char *str);
void				print_prompt(void);
void				setenv_pwd_(t_env *e, char *cwd);
void				print_list(t_env *e);
void				minishell__(t_tools *t, char **env);
void				minishell_loop(t_tools *t, char **env);
void				ft_env_(char **av1, char **av2);
char				*error_cd(char *path);
void				setenv_pwd(t_env *e, char *av);
void				setenv_old_pwd(t_env *e);
void				creat_maillon(t_env **e, char *av, t_env *tmp);
char				*path_(char *path, char *tmp, char *line, char *split);
int					tools6(char *av);
void				tools5(t_env *tmp);
void				tools4(t_env *tmp, char *split);
void				tools_free(char *name, char *value, char *path, t_env *tmp);
void				tools3(char **env, char **av, char *tmp);
void				setup_int(t_tools *t);
void				free_listee(t_env **e);
int					ft_env(char *av, t_env *e, char *av1);
t_tools				*init_tools(char **av, t_env *e, char **env);
void				minishell(t_tools *t, char *cwd, char *toto);
int					tools(t_env **e, char *av0, char *av1);
void				tools_value(t_env *tmp, int k);
char				*tools_join(char *name, char *value);
char				*cd_tools3(t_env *e);
int					cd_tools2(char *path);
int					cd_tools(char *path, t_env *e);
void				chdir_err(char *path);
void				echo_display(char *av);
char				*parser(char *line, char **env);
int					ft_echo(char **av);
int					update_value(t_env **e, char *check, char *av, t_env *tmp);
int					setenv_list(t_env **e, char *check, char *av);
char				**envi(t_env *e);
void				display_err(char *tmp);
void				display_error(char *path);
int					parser_stat(char *line, char *check, t_env *e);
void				display_list(t_env *e);
void				add_list(t_env **e, char *path);
int					get_cd(char *path, char *av, t_env *e);
t_env				*new_list(char *path);
int					len_list(t_env *e);
int					unsetenv_list(t_env **e, char *check, char *av);
void				ft_tabfree(char **tab);
int					create_value_name(char *path);

#endif
