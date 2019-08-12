/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/12 12:22:04 by mimeyer          ###   ########.fr       */
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
