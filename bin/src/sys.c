/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 08:57:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 09:17:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_sys(char **cmds)
{
	pid_t pid;
	char *path;
	char *func_p;
	int status;
	char **av;

	status = 1;
	path = "/bin/";
	av = ft_strsplit(cmds[0], ' ');
	func_p = ft_strjoin(path, av[0]);
	if (!(pid = fork()))
		execve(func_p, av, m_env);
	waitpid(pid, &status, WUNTRACED);
	free(func_p);
	free_er(av);
	return (1);
}
