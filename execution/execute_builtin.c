/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:30 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:30 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "../parser/parser.h"

int	single_builtin(t_list *cmd_lst, t_shell_data *envp)
{
	t_execute	*cmd_with_fds;
	t_ast		*cmd;

	cmd_with_fds = cmd_lst->content;
	cmd = cmd_with_fds->command;
	if (ft_lstsize(cmd_lst) != 1)
		return (ERROR);
	else if (cmd->argv[0] == NULL)
		return (ERROR);
	else if (!is_p_builtin_name(cmd->argv[0]))
		return (ERROR);
	if (cmd->redirs)
		handle_redir_input_output(cmd_lst);
	if (ft_strcmp(cmd->argv[0], "exit") == 0 && cmd->argc <= 2)
	{
		free(cmd_lst);
		free(cmd_with_fds);
	}
	envp->exit_status = p_execute_built(cmd, envp);
	return (SUCCESS);
}
