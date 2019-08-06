/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 12:11:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_cd(char *cmd)
{
	char **path;

	path = ft_strsplit(cmd, ' ');
	if (path[1] == NULL || (ft_strcmp(path[1], "~") == 0))
		exec_cd_home();
	else 
	{
		if (chdir(path[1]) != 0) {
			ft_putstr("SHIT JUST BROKE\n");
		}
	}
	free_er(path);
	return (1);
}

void exec_cd_home(void)
{
	int i;
	char *home;
	int len;

	i = 0;
	while(m_env[i])
	{
		if (ft_strncmp(m_env[i], "HOME=", 5) == 0)
		{
			len  = ft_strlen(m_env[i]);
			home = ft_strsub(m_env[i], 5, len - 5);
			if (chdir(home) != 0)
			{
				ft_putstr("HOME JUST BROKE\n");
			}
			free(home);
			break ;
		}
		i++;
	}
}
