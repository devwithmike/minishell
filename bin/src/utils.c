/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/08 14:30:51 by mimeyer          ###   ########.fr       */
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
}

void	get_home(char *path)
{
	int len;

	if (ft_strncmp(path, "HOME=", 5) == 0)
	{
		len  = ft_strlen(path);
		home = ft_strsub(path, 5, len - 5);
	}
}

void	get_path(void)
{
	int i;

	i = 0;
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], "PATH=", 5) == 0)
		{
			path = ft_strsub(m_env[i], 5, ft_strlen(m_env[i]) - 5);
			break ;
		}
		i++;
	}
}
