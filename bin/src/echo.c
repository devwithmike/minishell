/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:37:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/15 14:45:12 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_echo(char **cmd)
{
	int i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i + 1] == NULL)
			ft_putendl(cmd[i]);
		else
			ft_putstr(cmd[i]);
		i++;
	}
	free_er(cmd);
	return (1);
}
