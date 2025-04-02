/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:00:36 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/02 15:57:27 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_tokens	*copy_token(t_token_type type, char *value)
{
	t_tokens	*copy;

	copy = malloc(sizeof(t_tokens));
	if (!copy)
		return (NULL);
	ft_bzero(copy, sizeof(t_tokens));
	copy->token_type = type;
	copy->value = ft_strdup(value);
	if (!copy->value)
	{
		free(copy);
		return (NULL);
	}
	return (copy);
}

void	handle_redirection(t_ast *node, t_tokens **tokens)
{
	t_tokens	*current;

	if (!node || !tokens || !*tokens || !(*tokens)->next)
		return ;
	current = *tokens;
	*tokens = (*tokens)->next;
	if (!*tokens)
		return ;
	if (current->token_type == REDIRIN || current->token_type == HEREDOC)
	{
		if (node->infile)
			free(node->infile);
		node->infile = copy_token(current->token_type, (*tokens)->value);
		if (!node->infile)
			return ;
	}
	else if (current->token_type == REDIROUT || current->token_type == APPEND)
	{
		if (node->outfile)
			free(node->outfile);
		node->outfile = copy_token(current->token_type, (*tokens)->value);
		if (!node->outfile)
			return ;
	}
}

void	add_argument(t_ast *node, char *arg)
{
	int		i;
	char	**new_args;

	if (!node || !arg)
		return ;
	i = 0;
	while (node->argv && node->argv[i])
		i++;
	new_args = malloc(sizeof(char *) * (i + 2));
	if (!new_args)
		return ;
	i = 0;
	while (node->argv && node->argv[i])
	{
		new_args[i] = node->argv[i];
		i++;
	}
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;
	free(node->argv);
	node->argv = new_args;
}

void	handle_token(t_ast *current, t_tokens **tokens)
{
	while (*tokens && (*tokens)->token_type != PIPE)
	{
		if ((*tokens)->token_type == REDIRIN \
			|| (*tokens)->token_type == REDIROUT \
			|| (*tokens)->token_type == HEREDOC \
			|| (*tokens)->token_type == APPEND)
			handle_redirection(current, tokens);
		else
			add_argument(current, (*tokens)->value);
		*tokens = (*tokens)->next;
	}
}
