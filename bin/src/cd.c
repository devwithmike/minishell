/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 15:42:27 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		exec_path(char *path)
{
	char	cwd[1024];

	reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
	if (chdir(path) != 0)
		ft_putstr("PATH JUST BROKE\n");
	return (1);
}

int		exec_cd(char **cmd)
{
	char	*dir;
	char	*home;
	char	cwd[1024];

	home = get_env("HOME=");
	if (cmd[1] == NULL || (ft_strcmp(cmd[1], "~") == 0))
		exec_path(home);
	else if ((ft_strchr(cmd[1], '~') != NULL) && (ft_strlen(cmd[1]) > 1))
	{
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		dir = ft_strjoin(home, ft_strchr(cmd[1], '~') + 1);
		if (chdir(dir) != 0)
			ft_putstr("HOME PATH JUST BROKE\n");
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
	int		i;
	char	*temp;
	char	cwd[1024];

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
