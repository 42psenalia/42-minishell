/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:59:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/02 14:30:20 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*find_value(char *dollar, t_shell_data *data)
{
	t_envar_list	*list;
	t_envar			*env;

	if (ft_strcmp(dollar, "$?") == 0)
		return (ft_itoa(data->exit_status));
	list = data->envar_list;
	while (list)
	{
		env = list->content;
		if (ft_strcmp(dollar + 1, env->key) == 0)
			return (ft_strdup(env->value));
		list = list->next;
	}
	return (ft_strdup(""));
}

static t_tokens	*lexermini(char *input)
{
	t_tokens		*head;
	char			*word;
	int				init;
	int				i;

	head = NULL;
	word = NULL;
	init = 0;
	i = 0;
	while (input[i])
	{
		while (input[i] != '$' && input[i] != '\0')
			i++;
		if (i > init)
			word = ft_substr(input, init, i - init);
		else
			word = get_dollar(input, &i);
		if (word)
			maketokenlst(&head, word);
		init = i;
	}
	return (head);
}

static void	searchnreplace(t_tokens *lexer, t_shell_data *data)
{
	char	*dollar;

	while (lexer)
	{
		if (lexer->token_type == DOLLAR)
		{
			dollar = find_value(lexer->value, data);
			free(lexer->value);
			lexer->value = dollar;
		}
		lexer = lexer->next;
	}
	return ;
}

static char	*arglue(t_tokens *lexer)
{
	char	*result;
	char	*temp;

	result = NULL;
	while (lexer)
	{
		if (!result)
			result = ft_strdup(lexer->value);
		else
		{
			temp = ft_strjoin(result, lexer->value);
			if (!temp)
				return (NULL);
			free(result);
			result = temp;
		}
		lexer = lexer->next;
	}
	return (result);
}

void	handle_dollar(t_tokens *token, t_shell_data *data)
{
	char		*value;
	t_tokens	*lex2;

	value = NULL;
	if (token->token_type == DOLLAR)
		value = find_value(token->value, data);
	else
	{
		lex2 = lexermini(token->value);
		if (!lex2)
			return ;
		searchnreplace(lex2, data);
		value = arglue(lex2);
		free_tokens(lex2);
	}
	if (!value)
	{
		data->exit_status = ENOMEM;
		return ;
	}
	free(token->value);
	token->value = value;
}
