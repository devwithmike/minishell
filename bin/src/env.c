/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:29:35 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/16 14:46:53 by mimeyer          ###   ########.fr       */
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
	if (cmd[1] == NULL || cmd[2] == NULL)
		return (error_params(cmd, -1));
	if (cmd[3])
		return (error_params(cmd, 1));
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
	char *temp;

	i = 0;
	if (cmd[1] && cmd[2])
		return (error_params(cmd, 1));
	else if (cmd[1] == NULL)
		return (error_params(cmd, -1));
	if (cmd[1][0] == '$')
		temp = get_env(cmd[1] + 1);
	else
		temp = ft_strdup(cmd[1]);
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], temp, ft_strlen(temp)) == 0)
		{
			ft_strdel(&m_env[i]);
			free_er(cmd);
			free(temp);
			return (1);
		}
		i++;
	}
	free(temp);
	return (0);
}
