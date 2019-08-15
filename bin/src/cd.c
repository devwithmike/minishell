/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 14:39:12 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_cd(char **cmd)
{
	char *dir;
	char cwd[1024];
	char *home;

	home = get_env("HOME=");
	if (cmd[1] == NULL || (ft_strcmp(cmd[1], "~") == 0))
	{
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		if (chdir(home) != 0)
			ft_putstr("HOME JUST BROKE\n");
	}
	else if ((ft_strchr(cmd[1], '~') != NULL) && (ft_strlen(cmd[1]) > 1))
	{
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		dir = ft_strjoin(home, ft_strchr(cmd[1], '~') + 1);
		if (chdir(dir) != 0)
			ft_putstr("HOME PATH JUST BROKE\n");
		free(dir);
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		exec_prev();
	}
	else 
	{
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		if (chdir(cmd[1]) != 0)
			ft_putstr("SHIT JUST BROKE\n");
	}
	reset_env("PWD", getcwd(cwd, sizeof(cwd)));
	free_er(cmd);
	return (1);
}

int exec_tilda(char **cmd)
{
	char *home;
	char *dir;
	char *temp;
	char *path;

	home = get_env("HOME=");
	if (ft_strlen(cmd[0]) > 1)
	{
		dir = ft_strdup(cmd[0] + 1);
		temp = ft_strjoin(home, "/");
		path = ft_strjoin(temp, dir);
		free(dir);
		free(temp);
		free(home);
		if (chdir(path) != 0)
			ft_putstr("TILDA PATH JUST BROKE\n");
		free(path);
		free_er(cmd);
		return (1);
	}
	else
	{
		if (chdir(home) != 0)
			ft_putstr("TILDA PATH JUST BROKE\n");
		free(home);
		free_er(cmd);
		return (1);
	}
	return (0);
}

void exec_prev(void)
{
	int i;
	char *temp;
	char cwd[1024];

	i = 0;
	temp = ft_strdup(getcwd(cwd, sizeof(cwd)));
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], "OLDPWD=", 7) == 0)
		{
			if (chdir(ft_strsub(m_env[i], 7, ft_strlen(m_env[i]) - 7)) != 0)
				ft_putstr("BACK JUST BROKE\n");
			break ;
		}
		i++;
	}
	reset_env("OLDPWD", temp);
	free(temp);
}
