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
#include "../parser/parser.h"

static void	redir_input_type_file(t_list *cmd_lst, t_tokens *file, int type)
{
	t_execute	*cmd;

	if (file->type != WORD)
		return ;
	cmd = cmd_lst->content;
	if (type == REDIRIN)
	{
		cmd->fd_in = open(file->value, O_RDONLY);
	}
	else if (type == HEREDOC)
		cmd->fd_in = cmd->fd_heredoc;
	if (cmd->fd_in == -1)
	{
		perror(file->value);
		return ;
	}
}

static void	redir_output_type_file( t_list *cmd_lst, t_tokens *file, int type)
{
	int			mode;
	t_execute	*cmd;

	if (file->token_type != WORD)
		return ;
	if (type == APPEND)
		mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		mode = O_WRONLY | O_CREAT | O_TRUNC;
	cmd = cmd_lst->content;
	cmd->fd_out = open(file->value, mode, 0644);
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
	t_ast		*redirs;
	t_execute	*exe_cmd;

	exe_cmd = cmd_lst->content;
	redirs = exe_cmd->command;
	while (redirs)
	{
		redirs = redirs->next;
		if (redirs->infile)
			redir_input_type_file(cmd_lst, redirs->infile, REDIRIN);
		else if (redirs->outfile == HEREDOC)
			redir_input_type_file(cmd_lst, redirs->infile, HEREDOC);
		else if (operator->type == REDIROUT || operator->type == APPEND)
			redir_output_type_file(cmd_lst, filename, operator->type);
		redirs = redirs->next;
	}
	dup2(exe_cmd->fd_in, STDIN_FILENO);
}
