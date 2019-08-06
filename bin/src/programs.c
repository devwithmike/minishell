/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:29:40 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 10:41:29 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_cd(char *cmd)
{
	char **path;

	path = ft_strsplit(cmd, ' ');
	if (path[1] == NULL || path[1] == '~') {
		
	} else {
		if (chdir(path[1]) != 0) {
			ft_putstr("SHIT JUST BROKE\n");
		}
	}
	free_er(path);
	return (1);
}
