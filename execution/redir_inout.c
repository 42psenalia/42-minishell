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

static void	redir_input_type_file(t_list *cmd_lst, char *file, int type)
{
	t_execute	*cmd;

	if (get_token_type(file) != WORD)
		return ;
	cmd = cmd_lst->content;
	if (type == REDIRIN)
	{
		cmd->fd_in = open(file, O_RDONLY);
	}
	else if (type == HEREDOC)
		cmd->fd_in = cmd->fd_heredoc;
	if (cmd->fd_in == -1)
	{
		perror(file);
		return ;
	}
}

static void	redir_output_type_file( t_list *cmd_lst, char *file, int type)
{
	int			mode;
	t_execute	*cmd;

	if (get_token_type(file) != WORD)
		return ;
	if (type == APPEND)
		mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		mode = O_WRONLY | O_CREAT | O_TRUNC;
	cmd = cmd_lst->content;
	cmd->fd_out = open(file, mode, 0644);
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
		if (redirs->token == REDIRIN || redirs->token == HEREDOC)
			redir_input_type_file(cmd_lst, redirs->infile, redirs->token);
		else if (redirs->token == REDIROUT || redirs->token == APPEND)
			redir_output_type_file(cmd_lst, redirs->outfile, redirs->token);
		redirs = redirs->next;
	}
	dup2(exe_cmd->fd_in, STDIN_FILENO);
}
