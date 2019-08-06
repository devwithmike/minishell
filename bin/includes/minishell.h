/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimeyer <mimeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:25:23 by mimeyer           #+#    #+#             */
/*   Updated: 2019/08/06 09:52:35 by mimeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

char	**m_env;

int		execute_args(char **cmds);
int		check_sys(char **cmds);
int		exec_cd(char *cmd);
void	free_er(char **str);
void	print_path(void);
int		print_env(void);
void	pop_env(char **env);

#endif
