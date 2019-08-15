/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 14:39:04 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_er(char **str)
{
	int	i;
	i = 0;
	while (str[i])
		ft_strdel(&str[i++]);
	free(str);
}

void	print_path(void)
{
	char cwd[1024];
	char *ptr;
	char *home;
	
	home = get_env("HOME=");
	ft_putstr("\033[1;35m");
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (ft_strcmp(cwd, "/") == 0)
			ft_putchar('/');
		else if (ft_strcmp(cwd, home) == 0)
			ft_putstr("~/");
		else
		{
			ptr = ft_strsub(cwd, ft_strlen(home), ft_strlen(cwd));
			ft_putchar('~');
			ft_putstr(ptr);
			free(ptr);
		}
	}
	free(home);
}

char			*do_path(char *bin, char *com)
{
	char		*temp;
	char		*path;

	if (ft_strstr(bin, com) != NULL)
		path = ft_strdup(com);
	else
	{
		temp = ft_strjoin(bin, "/");
		path = ft_strjoin(temp, com);
		ft_strdel(&temp);
	}
	return (path);
}

char			*get_env(char *str)
{
	int			i;

	i = 0;
	while (m_env[i])
	{
		if (ft_strncmp(str, m_env[i], ft_strlen(str)) == 0)
			return (ft_strdup(ft_strchr(m_env[i], '=') + 1));
		i++;
	}
	return (NULL);
}

char			*get_path(char *com)
{
	int			i;
	char		*temp;
	char		**bin;
	char		*path;
	struct stat	info;

	i = -1;
	temp = get_env("PATH=");
	bin = ft_strsplit(temp, ':');
	ft_strdel(&temp);
	while (bin && bin[++i])
	{
		path = do_path(bin[i], com);
		if (lstat(path, &info) == -1)
			free(path);
		else
		{
			free_er(bin);
			return (path);
		}
	}
	if (bin != NULL)
		free_er(bin);
	return (NULL);
}

char			*end_quote(char *str, char q)
{
	char		*ptr;
	char		*temp;
	char		*str2;

	ptr = str;
	while ((ptr = ft_strchr(ptr, q)) != NULL)
	{
		ptr++;
		if ((ptr = ft_strchr(ptr, q)) == NULL)
		{
			if (q == '"')
				str2 = readline("\033[1;35mdquote$>\033[0m");
			else
				str2 = readline("\033[1;35mquote$>\033[0m");
			temp = ft_strjoin(str, "\n");
			ft_strdel(&str);
			str = ft_strjoin(temp, str2);
			ft_strdel(&str2);
			ft_strdel(&temp);
			ptr = str;
		}
		else
			ptr++;
	}
	return (str);
}
