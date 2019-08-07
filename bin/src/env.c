/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:29:35 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 08:22:46 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pop_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	m_env = (char **)malloc((sizeof(char *) * (i + 1)));
	i = 0;
	while (env[i])
	{
		m_env[i] = ft_strdup(env[i]);
		get_home(env[i]);
		i++;
	}
}

void	reset_env(char *key, char *value)
{
	int i;
	char *temp_key;
	char *temp;

	i = 0;
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], key, ft_strlen(key)) == 0)
		{
			temp_key = ft_strjoin(key, "=");
			temp = ft_strjoin(temp_key, value);
			ft_strdel(&m_env[i]);
			m_env[i] = ft_strdup(temp);
			free(temp_key);
			free(temp);
			break ;
		}
		i++;
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

int		print_env(void)
{
	int i;

	i = 0;
	while (m_env[i])
	{
		ft_putendl(m_env[i]);
		i++;
	}
	return (1);
}
