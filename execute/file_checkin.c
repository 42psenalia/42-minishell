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

	while (cmd)
	{
		if (!cmd->infile)
			return (SUCCESS);
		type = cmd->infile->token_type;
		if (type == REDIRIN)
		{
			if (access(cmd->infile->value, R_OK) != SUCCESS \
				|| (access(cmd->infile->value, R_OK | W_OK) != SUCCESS))
			{
				perror(cmd->infile->value);
				return (ERROR);
			}
		}
		cmd = cmd->next;
	}
	return (SUCCESS);
}
