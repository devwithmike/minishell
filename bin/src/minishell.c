/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/12 12:51:01 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int check_sys(char *cmd)
{
	if (ft_strnequ(cmd, "exit", 4))
	// {
	// 	ft_putendl("\033[1;36mGoodbye \U0001F60A\033[0m");
		return (-1);
	// }
	else if (ft_strnequ(cmd, "cd", 2))
		return (exec_cd(cmd));
	else if (ft_strnequ(cmd, "env", 3))
		return (print_env());
	else if (ft_strnequ(cmd, "setenv", 6))
		return (set_env(cmd));
	else if (ft_strnequ(cmd, "unsetenv", 8))
		return (unset_env(cmd));
	else if (ft_strnequ(cmd, "echo", 4))
		return (exec_echo(cmd));
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

// char *get_quotes(char **line)
// {

// }

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
		if (ft_strchr(line, '"') != NULL)
			line = end_quote(line, '"');
		else if (ft_strchr(line, '\'') != NULL)
			line = end_quote(line, '\'');
		add_history(line);
		//line = ft_strsub(line, 2, ft_strlen(line) - 1);
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands);
		free_er(commands);
	}
	free_er(m_env);
}
