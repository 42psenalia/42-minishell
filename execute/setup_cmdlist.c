/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmdlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:01:11 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:01:11 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	*make_execute_command(void *command)
{
	t_execute	*cmd;

	cmd = malloc(sizeof(t_execute));
	if (cmd == NULL)
		return (NULL);
	cmd->command = command;
	cmd->pipe_fds[0] = -1;
	cmd->pipe_fds[1] = -1;
	cmd->fd_prev = -1;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	cmd->fd_heredoc = -1;
	cmd->pid = -1;
	return (cmd);
}

void	free_execute_command(void *execute_command)
{
	t_execute	*cmd;

	cmd = execute_command;
	free_ast(cmd->command);
	free(cmd);
}

t_list	*init_execute_command_list(t_list *commands)
{
	t_list	*execute_command_list;

	execute_command_list = ft_lstmap(commands, \
		make_execute_command, free_execute_command);
	if (execute_command_list == NULL)
		return (NULL);
	return (execute_command_list);
}

void	free_execute_command_list(t_list **execute_command_list)
{
	ft_lstclear(execute_command_list, free_execute_command);
}
