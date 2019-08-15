/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:29:35 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 15:08:55 by mimeyer          ###   ########.fr       */
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
		i++;
	}
}

int		reset_env(char *key, char *value)
{
	int		i;
	char	*temp;
	char	*temp_key;

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
			return (1);
		}
		i++;
	}
	return (0);
}

int		print_env(char **cmd)
{
	int i;

	i = 0;
	while (m_env[i])
	{
		ft_putendl(m_env[i]);
		i++;
	}
	free_er(cmd);
	return (1);
}

int		set_env(char **cmd)
{
	int		i;
	char	**temp;
	char	*temp_key;
	char	*temp_rule;

	i = 0;
	if (reset_env(cmd[1], cmd[2]))
	{
		free_er(cmd);
		return (1);
	}
	while (m_env[i])
		i++;
	temp = (char **)malloc((sizeof(char *) * (i + 2)));
	i = -1;
	while (m_env[++i])
		temp[i] = ft_strdup(m_env[i]);
	temp_key = ft_strjoin(cmd[1], "=");
	temp_rule = ft_strjoin(temp_key, cmd[2]);
	free(temp_key);
	free_er(cmd);
	temp[i] = ft_strdup(temp_rule);
	free(temp_rule);
	free_er(m_env);
	pop_env(temp);
	free_er(temp);
	return (1);
}

int		unset_env(char **cmd)
{
	int i;

	i = 0;
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], cmd[1], ft_strlen(cmd[1])) == 0)
		{
			ft_strdel(&m_env[i]);
			free_er(cmd);
			return (1);
		}
		i++;
	}
	return (0);
}
