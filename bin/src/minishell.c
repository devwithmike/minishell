/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 10:32:59 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_sys(char **cmds)
{
	if (ft_strnequ(cmds[0], "exit", 4))
		return (-1);
	else if (ft_strnequ(cmds[0], "cd", 2))
		return (exec_cd(cmds[0]));
	else if (ft_strnequ(cmds[0], "env", 3))
		return (print_env());
	return (0);
}

int execute_args(char **cmds)
{
	int i;

	i = 0;
	while (cmds[i] != NULL)
	{
		if (check_sys(cmds) == -1)
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
	system("clear");
	pop_env(env);
	while (i)
	{
		print_path();
		line = readline("$>");
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands);
		free_er(commands);
	}
	free_er(m_env);
}
