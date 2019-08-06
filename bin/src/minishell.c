/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 09:29:14 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_sys(char **cmds, char **env)
{
	if (ft_strnequ(cmds[0], "exit", 4))
		return (-1);
	else if (ft_strnequ(cmds[0], "cd", 2))
		return (exec_cd(cmds[0]));
	else if (ft_strnequ(cmds[0], "pwd", 3))
	{
		get_path();
		ft_putchar('\n');
		return (1);
	}
	else if (ft_strnequ(cmds[0], "env", 3))
		return (print_env(env));
	return (0);
}

int execute_args(char **cmds, char **env)
{
	int i;

	i = 0;
	while (cmds[i] != NULL)
	{
		if (check_sys(cmds, env) == -1)
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
	(void)env;
	i = 1;
	system("clear");
	while (i)
	{
		get_path();
		line = readline("$>");
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands, env);
		free_er(commands);
	}
}
