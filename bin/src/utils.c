/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 10:33:38 by mimeyer          ###   ########.fr       */
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
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_putstr(cwd);
}

void	pop_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
		i++;
	m_env = (char **)malloc((sizeof(char *) * (i + 1)));
	i = 0;
	while (env[i] != NULL)
	{
		m_env[i] = ft_strdup(env[i]);
		i++;
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
