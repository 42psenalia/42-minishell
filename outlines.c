/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:29 by psenalia          #+#    #+#             */
/*   Updated: 2024/12/19 17:59:21 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

void	addtoken(int c, t_tokencount *tokens, int i)
{
	if (c == 0)
		tokens->squote++;
	if (c == 1)
		tokens->dquote++;
	if (c == 2)
		tokens->dollar++;
	if (c == 3)
		tokens->pipe++;
	if (c == 4)
		tokens->redirin++;
	if (c == 5)
		tokens->redirout++;
	if (c == 6)
		tokens->heredoc++;
	if (c == 7)
		tokens->append++;
	return ;
}

void	tokenread(char *input)
{
	t_tokencount	tokens;
	int				i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 39) //'
			addtoken(SQUOTE, &tokens, i);
		else if (input[i] == 34) //"
			addtoken(DQUOTE, &tokens, i);
		else if (input[i] == 60 && input[i + 1] == 60) //<<
		{
			addtoken(HEREDOC, &tokens, i);
			i++;
		}
		else if (input[i] == 60) //<
			addtoken(REDIRIN, &tokens, i);
		else if (input[i] == 62 && input[i + 1] == 62) //>>
		{
			addtoken(APPEND, &tokens, i);
			i++;
		}
		else if (input[i] == 62) //>
			addtoken(REDIROUT, &tokens, i);
		else if (input[i] == 124) //|
			addtoken(PIPE, &tokens, i);
		else if (input[i] == 36) //$
			addtoken(DOLLAR, &tokens, i);
		i++;
	}
}
