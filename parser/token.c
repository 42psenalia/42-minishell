/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:28:48 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/01 15:38:46 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_token(t_tokens **head, t_token_type type, char *value)
{
	t_tokens	*new;
	t_tokens	*temp;

	if (!value)
		return ;
	new = malloc(sizeof(t_tokens));
	if (!new)
		return ;
	new->token_type = type;
	new->value = value;
	new->spaces = 0;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	maketokenlst(t_tokens **head, char *word)
{
	if (ft_strchr(word, '$'))
		add_token(head, DOLLAR, word);
	else
		add_token(head, WORD, word);
	if (!*head)
		return (ERROR);
	return (SUCCESS);
}

char	*get_dollar(char *input, int *i)
{
	char	*token;
	int		init;

	if (input[*i] != '$')
		return (NULL);
	init = *i;
	(*i)++;
	while (ft_isalnum(input[*i]))
		(*i)++;
	token = ft_substr(input, init, *i - init);
	if (!token)
		return (NULL);
	return (token);
}

t_token_type	get_token_type(char *str)
{
	if (!str)
		return (-1);
	if (!ft_strcmp(str, "|"))
		return (PIPE);
	if (!ft_strcmp(str, "<"))
		return (REDIRIN);
	if (!ft_strcmp(str, ">"))
		return (REDIROUT);
	if (!ft_strcmp(str, "<<"))
		return (HEREDOC);
	if (!ft_strcmp(str, ">>"))
		return (APPEND);
	if (str[0] == '$')
		return (DOLLAR);
	if (str[0] == '\'')
		return (SQUOTE);
	if (str[0] == '"')
		return (DQUOTE);
	return (WORD);
}
