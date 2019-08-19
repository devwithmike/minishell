/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/19 13:18:25 by mimeyer          ###   ########.fr       */
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

char	*get_env(char *str)
{
	int	i;

	i = 0;
	while (m_env[i])
	{
		if (ft_strncmp(str, m_env[i], ft_strlen(str)) == 0)
			return (ft_strdup(ft_strchr(m_env[i], '=') + 1));
		i++;
	}
	return (NULL);
}

char	*end_quote(char *str, char q)
{
	char	*ptr;
	char	*temp;
	char	*str2;

	ptr = str;
	while ((ptr = ft_strchr(ptr, q)) != NULL)
	{
		ptr++;
		if ((ptr = ft_strchr(ptr, q)) == NULL)
		{
			if (q == '"')
				str2 = readline("\033[1;35mdquote$> \033[0m");
			else
				str2 = readline("\033[1;35mquote$> \033[0m");
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
