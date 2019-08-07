/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 08:57:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 11:33:18 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_sys(char *cmd)
{
	pid_t pid;
	char **path_t;
	char *func_p;
	char *func_t;
	int status;
	char **av;
	int i = 0;
	struct stat	sb;

	status = 1;
	path_t = ft_strsplit(path, ':');
	av = ft_strsplit(cmd, ' ');
	while (path_t[i])
	{
		func_t = ft_strjoin("/", av[0]);
		func_p = ft_strjoin(path_t[i], func_t);
		free(func_t);
		if (lstat(func_p, &sb) == 0)
		{
			if (!(pid = fork()))
				execve(func_p, av, m_env);
			waitpid(pid, &status, WUNTRACED);
			free(func_p);
			break ;
		}
		free(func_p);
		i++;
	}
	free_er(av);
	free_er(path_t);
	return (1);
}
