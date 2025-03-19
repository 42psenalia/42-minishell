/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processwait.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:59 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:59 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	wait_for_all_processes(t_list *cmd_lst)
{
	int			status;
	int			exit_status;
	t_execute	*cmd;

	status = SUCCESS;
	exit_status = SUCCESS;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (cmd->pid > 0)
			waitpid(cmd->pid, &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_status = WTERMSIG(status) + 128;
		cmd_lst = cmd_lst->next;
	}
	return (exit_status);
}
