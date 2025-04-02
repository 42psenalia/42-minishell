/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_reprise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:23:51 by psenalia          #+#    #+#             */
/*   Updated: 2025/04/02 13:48:53 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	checknext(t_tokens **tokens, t_token_type *type)
{
	*type = (*tokens)->next->token_type;
	if (*type == WORD || *type == DOLLAR || *type == SQUOTE || *type == DQUOTE)
		*tokens = (*tokens)->next;
}

static char	*mergeargs(t_tokens **tokens)
{
	t_token_type	type;
	char			*merged;
	char			*temp;

	type = (*tokens)->token_type;
	merged = NULL;
	while (type == WORD || type == DOLLAR || type == SQUOTE || type == DQUOTE)
	{
		if (!merged)
			merged = ft_strdup((*tokens)->value);
		else
		{
			temp = ft_strjoin(merged, (*tokens)->value);
			free(merged);
			merged = temp;
		}
		if (!(*tokens)->spaces && (*tokens)->next)
			checknext(tokens, &type);
		else
			break ;
	}
	return (merged);
}

t_tokens	*reprisetokens(t_tokens *tokens)
{
	t_tokens		*new;
	t_token_type	type;
	char			*merged;

	new = NULL;
	merged = NULL;
	while (tokens)
	{
		type = tokens->token_type;
		if (type == WORD || type == DOLLAR || type == SQUOTE || type == DQUOTE)
		{
			merged = mergeargs(&tokens);
			if (!merged)
				return (NULL);
		}
		else
			merged = ft_strdup(tokens->value);
		add_token(&new, get_token_type(merged), merged);
		merged = NULL;
		tokens = tokens->next;
	}
	if (!new)
		return (NULL);
	return (new);
}
