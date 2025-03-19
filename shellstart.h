/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellstart.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:26:22 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/11 15:26:22 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLSTART_H
# define SHELLSTART_H

# include "minishell.h"
# include "envar/envar.h"
# include "libft/libft.h"

# define READMODE 0
# define EXECUTEMODE -1
# define SUCCESS 0
# define ERROR 1
# define END 0

# define SUCCESS_EXE SUCCESS
# define CATCH_ERROR ERROR
# define IMPROPER_CMD 2
# define ISSUE_PATH 127
# define FATAL_ERROR 130
# define OUT_RANGE 255

typedef int	t_exit_status;

typedef struct s_shell_data
{
	t_exit_status	exit_status;
	t_envar_list	*envar_list;
}	t_shell_data;


t_shell_data	*initialize(int argc, char **argv, char **env);
void			silent_cntl(void);
void			restore_terminal_settings(void);
void			setup_signal(void);
t_shell_data	*makeshell(int argc, char **argv, char **env);
void			freeshell(t_shell_data *data);

#endif
