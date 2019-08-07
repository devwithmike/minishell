/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:37:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 14:04:57 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_echo(char *cmd)
{
	char *av;
	int i;

	i = 1;
	av = ft_strtrim(ft_strsub(cmd, 5, ft_strlen(cmd) - 5));
	ft_putendl(av);
	return (1);
}
