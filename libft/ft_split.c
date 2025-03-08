/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:48:20 by tbayrakt          #+#    #+#             */
/*   Updated: 2024/03/08 11:17:55 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Malloc space for have string and if something fails clean prev mallocs
int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (token_v[position] == NULL)
	{
		while (i < position)
			free(token_v[i++]);
		free(token_v);
		return (1);
	}
	return (0);
}

// Return 0 if all mallocs went fine, otherwise 1
int	fill(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

int	count_tokens(const char *s, char delimeter)
{
	int	tokens;
	int	in_tokens;

	tokens = 0;
	while (*s)
	{
		in_tokens = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			if (!in_tokens)
			{
				tokens++;
				in_tokens = 1;
			}
			s++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (!s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (token_v == NULL)
		return (NULL);
	token_v[tokens] = NULL;
	if (fill(token_v, s, c))
		return (NULL);
	return (token_v);
}

// Line: 25 - Free token also i++
// Line: 42 - Skip delimeters
// Line: 44 - Calc the len of token moving the ptr in the overall s
// Line: 88 - argv
// Line: 96 - Null pointer array
// Line: 97 - Copy all the strings in the correct position