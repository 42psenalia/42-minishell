/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:59:28 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/02 14:19:09 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*extract_word(char **input, t_token_type *type)
{
	char	*start;
	char	*result;
	int		len;

	start = *input;
	len = 0;
	while (**input && !is_space(**input) && !is_special(**input))
	{
		len++;
		(*input)++;
	}
	result = ft_substr(start, 0, len);
	*type = get_token_type(result);
	return (result);
}

static char	*extract_quoted(char **input, char quote_type, t_token_type *type)
{
	char	*start;
	char	*result;
	char	c;
	int		len;

	(*input)++;
	start = *input;
	len = 0;
	while (**input && **input != quote_type)
	{
		len++;
		(*input)++;
	}
	if (**input != quote_type)
	{
		ft_putstr_fd("minishell: quote error\n", STDERR_FILENO);
		return (NULL);
	}
	result = ft_substr(start, 0, len);
	c = **input;
	*type = c;
	(*input)++;
	return (result);
}

static char	*extract_operator(char **input, t_token_type *type)
{
	char	*result;

	if (**input == '|')
		result = ft_strdup("|");
	else if (**input == '<' && *(*input + 1) == '<')
	{
		result = ft_strdup("<<");
		(*input)++;
	}
	else if (**input == '>' && *(*input + 1) == '>')
	{
		result = ft_strdup(">>");
		(*input)++;
	}
	else if (**input == '<')
		result = ft_strdup("<");
	else
		result = ft_strdup(">");
	(*input)++;
	*type = get_token_type(result);
	return (result);
}

static void	idspaces(t_tokens *token, char *input)
{
	t_token_type	type;

	while (token->next)
		token = token->next;
	type = token->token_type;
	if (type == WORD || type == DOLLAR || type == SQUOTE || type == DQUOTE)
	{
		if (*input == ' ' || *input == '\t')
			token->spaces += 1;
	}
}

int	lexer(char *input, t_tokens **head)
{
	t_token_type	type;
	char			*word;

	while (*input)
	{
		word = NULL;
		if (*input == ' ' || *input == '\t')
			input++;
		else if (*input == '\'' || *input == '"')
		{
			word = extract_quoted(&input, *input, &type);
			if (!word)
				return (EINVAL);
		}
		else if (*input == '|' || *input == '<' || *input == '>')
			word = extract_operator(&input, &type);
		else
			word = extract_word(&input, &type);
		add_token(head, type, word);
		idspaces(*head, input);
	}
	return (SUCCESS);
}
