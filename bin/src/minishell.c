/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/05 09:47:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_sys(char **cmds)
{
	if (ft_strnequ(cmds[0], "exit", 4))
		return (-1);
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
	(void)env;
	i = 1;
	system("clear");
	while (i)
	{
		line = readline("$>");
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands);
		free(commands);
	}
}
