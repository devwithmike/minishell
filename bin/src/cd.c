/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/16 09:17:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exec_path(char *path)
{
	char	cwd[1024];

	reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
	if (chdir(path) != 0)
		error_found(path, "cd");
}

void	exec_env(char **cmd)
{
	char *temp;
	char *env;

	temp = ft_strsub(cmd[1], 1, ft_strlen(cmd[1]) - 1);
	env = get_env(temp);
	exec_path(env);
	free(temp);
	free(env);
}

int		exec_cd(char **cmd)
{
	char	*dir;
	char	*home;
	char	cwd[1024];

	home = get_env("HOME=");
	if (cmd[1] == NULL || (ft_strcmp(cmd[1], "~") == 0))
		exec_path(home);
	else if (cmd[1][0] == '$')
		exec_env(cmd);
	else if ((ft_strchr(cmd[1], '~') != NULL) && (ft_strlen(cmd[1]) > 1))
	{
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		dir = ft_strjoin(home, ft_strchr(cmd[1], '~') + 1);
		if (chdir(dir) != 0)
			error_found(dir, "cd");
		free(dir);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
		exec_prev();
	else
		exec_path(cmd[1]);
	reset_env("PWD", getcwd(cwd, sizeof(cwd)));
	free_er(cmd);
	free(home);
	return (1);
}

int		exec_tilda(char **cmd)
{
	char	*home;
	char	*temp;
	char	*path;

	home = get_env("HOME=");
	if (ft_strlen(cmd[0]) > 1)
	{
		temp = ft_strsub(cmd[0], 1, ft_strlen(cmd[0]) - 1);
		path = ft_strjoin(home, temp);
		free(temp);
		free(home);
		exec_path(path);
		free(path);
		free_er(cmd);
		return (1);
	}
	else
	{
		exec_path(home);
		free(home);
		free_er(cmd);
		return (1);
	}
	return (0);
}

void	exec_prev(void)
{
	char	*temp;
	char	cwd[1024];
	char	*dir;

	temp = ft_strdup(getcwd(cwd, sizeof(cwd)));
	dir = get_env("OLDPWD");
	if (chdir(dir) != 0)
		error_found(dir, "cd");
	reset_env("OLDPWD", temp);
	free(dir);
	free(temp);
}
