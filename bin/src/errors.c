/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:35:18 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/20 11:16:55 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_found(char *path, char *cmd)
{
	struct stat	sb;

	stat(path, &sb);
	if (S_ISREG(sb.st_mode))
	{
		ft_putstr(cmd);
		ft_putstr(": not a directory: ");
		ft_putendl(path);
	}
	else
	{
		ft_putstr(cmd);
		ft_putstr(": no such file or directory: ");
		ft_putendl(path);
	}
}

int		error_params(char **cmd, int i)
{
	if (i < 0)
	{
		ft_putstr(cmd[0]);
		ft_putendl(": to few arguments");
	}
	else
	{
		ft_putstr(cmd[0]);
		ft_putendl(": to many arguments");
	}
	free_her(cmd);
	return (0);
}
