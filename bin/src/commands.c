/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:15:05 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/20 11:12:51 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_help(void)
{
	ft_putendl("THIS IS THE HELP CMD");
	return (1);
}

int	exec_author(void)
{
	ft_putendl("MikeFMeyer");
	ft_putendl("https://github.com/MikeFMeyer");
	return (1);
}
