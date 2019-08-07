/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:37:22 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/07 16:01:23 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int exec_echo(char *cmd)
{
	char *av;
	char *temp;
	int i;

	i = 1;
	temp = ft_strsub(cmd, 5, ft_strlen(cmd) - 5);
	av = ft_strtrim(temp);
	ft_putendl(av);
	free(av);
	free(temp);
	return (1);
}
