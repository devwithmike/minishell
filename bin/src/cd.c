/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 15:43:20 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_cd(char *cmd)
{
	char **path;
	char *dir;
	char cwd[1024];

	reset_env("OLDPWD", getcwd(cwd, sizeof(cwd)));
	path = ft_strsplit(cmd, ' ');
	if (path[1] == NULL || (ft_strcmp(path[1], "~") == 0))
	{
		if (chdir(home) != 0)
			ft_putstr("HOME JUST BROKE\n");
		reset_env("PWD", home);
	}
	else if ((ft_strchr(path[1], '~') != NULL) && (ft_strlen(path[1]) > 1))
	{
		dir = ft_strjoin(home, ft_strchr(path[1], '~') + 1);
		if (chdir(dir) != 0)
			ft_putstr("HOME PATH JUST BROKE\n");
		reset_env("PWD", dir);
		free(dir);
	}
	else 
	{
		if (chdir(path[1]) != 0)
			ft_putstr("SHIT JUST BROKE\n");
		reset_env("PWD", path[1]);
	}
	free_er(path);
	return (1);
}
