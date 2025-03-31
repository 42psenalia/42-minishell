/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:15:46 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/03/31 12:15:46 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	issue_command_to_child(t_list **cmd_lst_first, t_list *cmd_lst,
		int *prev_fd, t_shell_data *envp)
{
	restore_terminal_settings();
	envp->exit_status = ft_childprocess(cmd_lst_first, cmd_lst, prev_fd, envp);
	free_execute_command_list(cmd_lst_first);
	builtin_exit(NULL, envp);
}

static bool	argchk(t_list *execlist)
{
	t_execute	*temp;
	t_ast		*intron;
	bool		inout;

	while (execlist)
	{
		temp = execlist->content;
		intron = temp->command;
		while (intron)
		{
			if (intron->argv)
				return (true);
			if (intron->infile && intron->outfile)
				inout = true;
			intron = intron->next;
		}
		execlist = execlist->next;
	}
	if (inout)
		return (true);
	return (false);
}

int	sub_execute(t_list **cmd_lst_first, t_shell_data *envp, int *prev_fd)
{
	t_list		*node;
	t_execute	*cmd;

	node = *cmd_lst_first;
	while (node)
	{
		cmd = node->content;
		if (argchk(node))
		{
			if (node->next && pipe(cmd->pipe_fds) == -1)
				exit(EXIT_FAILURE);
			cmd->pid = fork();
			if (cmd->pid < 0)
				exit(EXIT_FAILURE);
			if (cmd->pid == 0)
				issue_command_to_child(cmd_lst_first, node, prev_fd, envp);
			else
				ft_parentprocess(node, prev_fd, cmd);
		}
		node = node->next;
	}
	return (SUCCESS);
}

t_exit_status	main_execute(t_list **commands, t_shell_data *envp)
{
	t_list	*execute_command_list;
	int		prev_fd;
	int		exit_status;

	execute_command_list = init_execute_command_list(*commands);
	ft_lstclear(commands, NULL);
	if (execute_command_list == NULL)
		return (ERROR);
	run_heredocs(execute_command_list);
	prev_fd = -1;
	if (single_builtin(execute_command_list, envp) == SUCCESS)
	{
		free_execute_command_list(&execute_command_list);
		return (envp->exit_status);
	}
	sub_execute(&execute_command_list, envp, &prev_fd);
	exit_status = wait_for_all_processes(execute_command_list);
	silent_cntl();
	free_execute_command_list(&execute_command_list);
	return (exit_status);
}
