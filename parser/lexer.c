#include "parser.h"

char	*extract_word(char **input)
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
	return (result);
}


char	*extract_quoted(char **input, char quote_type, t_token_type *type)
{
	char	*start;
	char	*result;
	char	c;
	int		len;

	(*input)++; // Move past opening quote
	start = *input;
	len = 0;
	while (**input && **input != quote_type)
	{
		len++;
		(*input)++;
	}
	if (**input != quote_type) // Missing closing quote
		return (NULL);
	result = ft_substr(start, 0, len); // Extract quoted string
	c = **input;
	*type = c;
	(*input)++; // Move past closing quote
	return (result);
}

char	*extract_operator(char **input)
{
	char	*result;

	if (**input == '|')
		result = ft_strdup("|");
	else if (**input == '<' && *(*input + 1) == '<')
	{
		result = ft_strdup("<<");
		(*input)++; // Skip the second '<'
	}
	else if (**input == '>' && *(*input + 1) == '>')
	{
		result = ft_strdup(">>");
		(*input)++; // Skip the second '>'
	}
	else if (**input == '<')
		result = ft_strdup("<");
	else
		result = ft_strdup(">");

	(*input)++; // Move past the operator
	return (result);
}

t_tokens	*lexer(char *input)
{
	t_tokens		*head;
	t_token_type	type;
	char			*word;

	head = NULL;
	while (*input)
	{
		type = 0;
		word = NULL;
		if (*input == ' ' || *input == '\t')
			input++;
		else if (*input == '\'' || *input == '"')
			word = extract_quoted(&input, *input, &type);
		else if (*input == '|' || *input == '<' || *input == '>')
			word = extract_operator(&input);
		else
			word = extract_word(&input);
		if (word)
		{
			if (!type || !(type == SQUOTE || type == DQUOTE))
				type = get_token_type(word);
			add_token(&head, type, word);
		}
	}
	return (head);
}
