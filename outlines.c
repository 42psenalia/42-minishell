/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:29 by psenalia          #+#    #+#             */
/*   Updated: 2024/12/03 16:00:57 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

void	addtoken(char c, t_tokens *tokens, int i)
{
	if (c == 39)
		tokens->squote = i;
	if (c == 34)
		tokens->dquote = i;
	if (c == 36)
		tokens->dollar = i;
	if (c == 124)
		tokens->pipe = i;
	if (c == 60)
		tokens->redir = i;
	if (c == 62)
		tokens->outfil = i;
	if (c == 71)
		tokens->herdoc = i;
	if (c == 72)
		tokens->append = i;
	return ;
}

void	tokenread(char *input)
{
	t_tokens	tokens;
	int			i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 39) //'
			addtoken(39, &tokens, i);
		else if (input[i] == 34) //"
			addtoken(34, &tokens, i);
		else if (input[i] == 60 && input[i + 1] != 60) //<<
		{
			addtoken(71, &tokens, i);
			i++;
		}
		else if (input[i] == 60) //<
			addtoken(60, &tokens, i);
		else if (input[i] == 62 && input[i + 1] != 62) //>>
		{
			addtoken(72, &tokens, i);
			i++;
		}
		else if (input[i] == 62) //>
			addtoken(62, &tokens, i);
		else if (input[i] == 124) //|
			addtoken(124, &tokens, i);
		else if (input[i] == 36) //$
			addtoken(36, &tokens, i);
		i++;
	}
}
