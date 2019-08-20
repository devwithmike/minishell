/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:49:29 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/20 09:54:08 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path(char *com)
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

char	*do_path(char *bin, char *com)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(bin, "/");
	path = ft_strjoin(temp, com);
	ft_strdel(&temp);
	return (path);
}

void	print_path(void)
{
	char	cwd[1024];
	char	*ptr;
	char	*home;

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
	ft_putstr("$>\033[0m");
}
