/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:52:50 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 09:31:32 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void free_er(char **str)
{
	int	i;
	i = 0;
	while (str[i])
		ft_strdel(&str[i++]);
	free(str);
}

void get_path(void)
{
	char cwd[1024];
	
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_putstr(cwd);
}

int print_env(char **env)
{
	while (*env)
	{
		ft_putendl(*env);
		env++;
	}
	return (1);
}
