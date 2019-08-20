/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:37:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/20 11:16:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_echo(char **cmd)
{
	int		i;
	char	*temp;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '$')
		{
			temp = get_env(cmd[i] + 1);
			ft_putstr(temp);
			free(temp);
		}
		else
			ft_putstr(cmd[i]);
		if (cmd[i + 1] == NULL)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
	free_her(cmd);
	return (1);
}
