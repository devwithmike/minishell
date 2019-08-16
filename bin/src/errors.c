/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:35:18 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/16 09:18:06 by mimeyer          ###   ########.fr       */
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
