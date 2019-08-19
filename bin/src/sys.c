/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 08:57:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/19 13:10:14 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, proc_signal_handler);
	}
}

int		exec_sys(char **cmd)
{
	char		*temp;
	struct stat	info;
	char		*path;

	path = get_path(cmd[0]);
	if (path != NULL && cmd[0][0] != '~')
		return (sys_call(cmd, path));
	if (lstat(cmd[0], &info) != -1)
		if (S_ISREG(info.st_mode))
		{
			temp = ft_strdup(cmd[0]);
			return (sys_call(cmd, temp));
		}
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd[0]);
	if (cmd)
		free_er(cmd);
	return (0);
}

int		sys_call(char **cmd, char *path)
{
	pid_t		pid;

	signal(SIGINT, proc_signal_handler);
	pid = fork();
	if (!pid)
	{
		if (execve(path, cmd, m_env) == -1)
		{
			ft_putstr("minishell: premission denied: ");
			ft_putendl(path);
		}
	}
	else if (pid < 0)
	{
		ft_putstr("minishell: unable to fork process:");
		ft_putnbr(pid);
		ft_putchar('\n');
	}
	else
		wait(&pid);
	free(path);
	free_er(cmd);
	return (1);
}
