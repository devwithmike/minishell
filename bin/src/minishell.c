/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 09:23:10 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_sys(char *cmd)
{
	if (ft_strnequ(cmd, "exit", 4))
		return (-1);
	else if (ft_strnequ(cmd, "cd", 2))
		return (exec_cd(cmd));
	else if (ft_strnequ(cmd, "env", 3))
		return (print_env());
	else
		return (exec_sys(cmd));
	return (0);
}

int execute_args(char **cmds)
{
	int i;

	i = 0;
	while (cmds[i] != NULL)
	{
		if (check_sys(cmds[i]) == -1)
			return (0);
		else
			i++;
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	int i;
	char *line;
	char **commands;

	(void)ac;
	(void)av;
	i = 1;
	pop_env(env);
	while (i)
	{
		print_path();
		line = readline("$>\033[0m");
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands);
		free_er(commands);
	}
	free_er(m_env);
}
