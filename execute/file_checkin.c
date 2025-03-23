/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checkin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:38 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:38 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	check_infiles(t_ast *cmd)
{
	t_token_type	type;

	printf("infile check\n");
	while (cmd)
	{
		type = cmd->token;
		if (type == REDIRIN)
		{
			if (access(cmd->infile, R_OK) != SUCCESS \
				|| (access(cmd->infile, R_OK | W_OK) != SUCCESS))
			{
				perror(cmd->infile);
				return (ERROR);
			}
			// cmd = cmd->next;
			// type = cmd->token;
			// if (type == WORD)
			// {
			// 	if (access(cmd->infile, R_OK) != SUCCESS
			// 		|| (access(cmd->infile, R_OK | W_OK) != SUCCESS))
			// 	{
			// 		perror(cmd->infile);
			// 		return (ERROR);
			// 	}
			// }
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
