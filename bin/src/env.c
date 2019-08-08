/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:29:35 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/08 15:24:00 by mimeyer          ###   ########.fr       */
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
	get_path();
}

int		reset_env(char *key, char *value)
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
			return (1);
		}
		i++;
	}
	return (0);
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

int		set_env(char *cmd)
{
	int i;
	char **temp;
	char **values;
	char *temp_key;
	char *temp_rule;

	i = 0;
	values = ft_strsplit(cmd, ' ');
	if (reset_env(values[1], values[2]))
	{
		free_er(values);
		return (1);
	}
	while (m_env[i])
		i++;
	temp = (char **)malloc((sizeof(char *) * (i + 2)));
	i = 0;
	while (m_env[i])
	{
		temp[i] = ft_strdup(m_env[i]);
		i++;
	}
	temp_key = ft_strjoin(values[1], "=");
	temp_rule = ft_strjoin(temp_key, values[2]);
	free(temp_key);
	free_er(values);
	temp[i] = ft_strdup(temp_rule);
	free(temp_rule);
	free_er(m_env);
	free(home);
	free(path);
	pop_env(temp);
	free_er(temp);
	return (1);
}

int		unset_env(char *cmd)
{
	char **values;
	int i;

	i = 0;
	values = ft_strsplit(cmd, ' ');
	while (m_env[i])
	{
		if (ft_strncmp(m_env[i], values[1], ft_strlen(values[1])) == 0)
		{
			ft_strdel(&m_env[i]);
			free_er(values);
			return (1);
		}
		i++;
	}
	return (0);
}
