/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 09:28:06 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_cd(char *cmd)
{
	char **path;
	char *dir;
	char cwd[1024];

	path = ft_strsplit(cmd, ' ');
	if (path[1] == NULL || (ft_strcmp(path[1], "~") == 0))
	{
		if (chdir(home) != 0)
			ft_putstr("HOME JUST BROKE\n");
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
	}
	else if ((ft_strchr(path[1], '~') != NULL) && (ft_strlen(path[1]) > 1))
	{
		dir = ft_strjoin(home, ft_strchr(path[1], '~') + 1);
		if (chdir(dir) != 0)
			ft_putstr("HOME PATH JUST BROKE\n");
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
		free(dir);
	}
	else if (ft_strcmp(path[1], "-") == 0)
	{
		exec_prev();
	}
	else 
	{
		if (chdir(path[1]) != 0)
			ft_putstr("SHIT JUST BROKE\n");
		reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
	}
	reset_env("PWD", getcwd(cwd, sizeof(cwd)));
	free_er(path);
	return (1);
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
