/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_inout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:01:08 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:01:08 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	redir_input_type_file(t_list *cmd_lst, t_token *file, int type)
{
	t_execute	*cmd;

	if (file->type != WORD)
		return ;
	cmd = cmd_lst->content;
	if (type == INFILE)
	{
		cmd->fd_in = open(file->str, O_RDONLY);
	}
	else if (type == HEREDOC)
		cmd->fd_in = cmd->fd_heredoc;
	if (cmd->fd_in == -1)
	{
		perror(file->str);
		return ;
	}
}

static void	redir_output_type_file( t_list *cmd_lst, t_token *file, int type)
{
	int			mode;
	t_execute	*cmd;

	if (file->type != WORD)
		return ;
	if (type == APPEND)
		mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		mode = O_WRONLY | O_CREAT | O_TRUNC;
	cmd = cmd_lst->content;
	cmd->fd_out = open(file->str, mode, 0644);
	if (cmd->fd_out == -1)
	{
		perror("failed file descriptor");
		exit(EXIT_FAILURE);
	}
	dup2(cmd->fd_out, STDOUT_FILENO);
	close(cmd->fd_out);
}

void	handle_redir_input_output(t_list *cmd_lst)
{
	t_list		*redirs;
	t_execute	*exe_cmd;
	t_token		*operator;
	t_token		*filename;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command->redirs;
	while (redirs)
	{
		operator = redirs->content;
		redirs = redirs->next;
		filename = redirs->content;
		if (operator->type == INFILE || operator->type == HEREDOC)
			redir_input_type_file(cmd_lst, filename, operator->type);
		else if (operator->type == OUTFILE || operator->type == APPEND)
			redir_output_type_file(cmd_lst, filename, operator->type);
		redirs = redirs->next;
	}
	dup2(exe_cmd->fd_in, STDIN_FILENO);
}
