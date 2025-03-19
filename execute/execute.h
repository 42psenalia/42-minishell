/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:26:39 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/11 15:26:39 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <fcntl.h>

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "../shellstart.h"
# include "../minishell.h"
# include "../envar/envar.h"
# include "../parser/parser.h"
# include "../builtin/builtin.h"

typedef struct s_execute
{
	struct s_ast	*command;
	int				pipe_fds[2];
	int				fd_prev;
	int				fd_in;
	int				fd_out;
	int				fd_heredoc;
	pid_t			pid;
}	t_execute;

t_exit_status	main_execute(t_list **command, t_shell_data *envp);

void			handle_redir_input_output(t_list *cmd_lst);
int				ft_childprocess(t_list **cmd_lst_first, t_list *cmd_lst, \
				int *prev_fd, t_shell_data *envp);
void			ft_parentprocess(t_list *cmd_lst, int *prev_fd, t_execute *cmd);
int				wait_for_all_processes(t_list *cmd_lst);

t_list			*init_execute_command_list(t_list *commands);
void			free_execute_command_list(t_list **execute_command_list);
void			free_execute_command(void *execute_command);

char			*find_path(char *key, t_list *env_var_lst, char *cmd);
int				check_infiles(t_ast *cmd);
char			*join_path(char **full_path, char *cmd);

void			run_heredocs(t_list *cmd_lst);

int				single_builtin(t_list *cmd_lst, t_shell_data *envp);

#endif
