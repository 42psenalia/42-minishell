/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:58:08 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/03/31 17:03:04 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*ft_getcwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("getcwd failed");
		path = ft_strdup("(unknown)");
		if (!path)
		{
			fprintf(stderr, "Error: Memory allocation failed in ft_getcwd\n");
			exit(EXIT_FAILURE);
		}
	}
	return (path);
}

char	*get_dollar(char *input, int *i)
{
	char	*token;
	int		init;

	if (input[*i] != '$')
		return (NULL);
	(*i)++;
	init = *i;
	while (ft_isalnum(input[*i]))
		(*i)++;
	token = ft_substr(input, init, *i - init);
	if (!token)
		return (NULL);
	return (token);
}

int	maketokenlst(t_tokens *head, char *word)
{
	if (ft_strchr(word, '$'))
		add_token(&head, DOLLAR, word);
	else
		add_token(&head, WORD, word);
	if (!head)
		return (ERROR);
	return (SUCCESS);
}

int	is_special(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '\'' || c == '"');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
