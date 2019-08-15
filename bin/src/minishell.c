/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:26:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 14:55:13 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_sys(char **cmd)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	else if (ft_strequ(cmd[0], "cd"))
		return (exec_cd(cmd));
	else if (ft_strequ(cmd[0], "env"))
		return (print_env(cmd));
	else if (ft_strequ(cmd[0], "setenv"))
		return (set_env(cmd));
	else if (ft_strequ(cmd[0], "unsetenv"))
		return (unset_env(cmd));
	else if (ft_strequ(cmd[0], "echo"))
		return (exec_echo(cmd));
	else if (cmd[0][0] == '~')
		return (exec_tilda(cmd));
	else if (exec_sys(cmd) == 1)
		return (1);
	return (0);
}

char	**remove_quotes(char *str)
{
	int		i;
	char	**ret;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
		}
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = '"';
		i++;
	}
	ret = ft_strsplit(str, '"');
	return (ret);
}

int		execute_args(char **cmds)
{
	int		i;
	char	**args;

	i = 0;
	while (cmds[i])
	{
		args = remove_quotes(cmds[i]);
		if (check_sys(args) == -1)
			return (0);
		else
			i++;
	}
	return (1);
}

int		main(int ac, char **av, char **env)
{
	int		i;
	char	*line;
	char	**commands;

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
		commands = ft_strsplit(line, ';');
		free(line);
		i = execute_args(commands);
		free_er(commands);
	}
	free_er(m_env);
}
