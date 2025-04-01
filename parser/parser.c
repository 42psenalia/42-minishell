/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:55:16 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/01 15:38:31 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*read_line(void)
{
	char	*new_line;
	char	*prompt;
	char	*cwd;
	char	*temp;

	cwd = ft_getcwd();
	prompt = ft_strjoin(C, cwd);
	free(cwd);
	new_line = ft_strjoin(prompt, "> " RST);
	free(prompt);
	if (!new_line)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	temp = new_line;
	new_line = readline(new_line);
	free(temp);
	if (!new_line)
		return (NULL);
	if (*new_line != '\0')
		add_history(new_line);
	return (new_line);
}

void	print_tokens(t_tokens *tokens)
{
	while (tokens)
	{
		printf("Type: %d, Value: [%s], Next-> %p\n", tokens->token_type,
			tokens->value, tokens->next);
		tokens = tokens->next;
	}
}

void	print_ast(t_ast *node)
{
	int	i;

	while (node)
	{
		printf("Command: ");
		if (node->argv)
		{
			i = 0;
			while (node->argv[i])
			{
				printf("[%s] ", node->argv[i]);
				i++;
			}
		}
		else
			printf("(None)");
		if (node->infile)
			printf("\n  Input Redirect: <%s>", node->infile->value);
		if (node->outfile)
			printf("\n  Output Redirect: >%s", node->outfile->value);
		printf("\n----------------\n");
		node = node->next;
	}
}

static void	linkcommands(t_command **commands, t_ast *parsed)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return ;
	ft_bzero(new, sizeof(t_command));
	new->content = parsed;
	if (!(*commands))
		*commands = new;
	else
		ft_lstadd_back(commands, new);
}

static t_command	*make_commlist(t_tokens *tokens)
{
	t_command	*commands;
	t_ast		*parsed_tokens;
	t_command	*temp;

	commands = NULL;
	while (tokens)
	{
		parsed_tokens = parse_tokens(&tokens);
		if (!parsed_tokens)
			return (NULL);
		print_ast(parsed_tokens);
		linkcommands(&commands, parsed_tokens);
		if (tokens)
			tokens = tokens->next;
	}
	temp = commands;
	while (temp)
	{
		printf("Command: %p, next-> %p\n", temp->content, temp->next);
		temp = temp->next;
	}
	return (commands);
}

static int	convertdollar(t_tokens *tokens, t_shell_data *data)
{
	t_tokens	*temp;

	temp = tokens;
	while (tokens)
	{
		if (tokens->token_type == DOLLAR \
			|| ((tokens->token_type == WORD \
			|| tokens->token_type == DQUOTE) \
			&& ft_strchr(tokens->value, '$')))
			handle_dollar(tokens, data);
		tokens = tokens->next;
	}
	while (temp)
	{
		if (!temp->value)
			return (ERROR);
		temp = temp->next;
	}
	return (SUCCESS);
}

// int	reprisetokens(t_tokens *tokens)
// {
// 	t_tokens		*new;
// 	t_token_type	type;

// 	new = NULL;
// 	while (tokens)
// 	{
// 		type = tokens->token_type;
// 		if ((type == WORD || type == DOLLAR || type == SQUOTE || \
// 			type = DQUOTE) && tokens->spaces > 1)
// 		else if ()
// 		tokens = tokens->next;
// 	}
// }

int	parser(char *line, t_command **commands, t_shell_data *data)
{
	t_tokens	*tokens;

	if (ft_strlen(line) == 0)
		return (SUCCESS);
	tokens = lexer(line);
	if (!tokens)
	{
		ft_putstr_fd("Lexer failed!\n", STDERR_FILENO);
		return (EINVAL);
	}
	print_tokens(tokens);
	if (convertdollar(tokens, data) == ERROR /*|| reprisetokens(tokens) == ERROR*/)
		return (ENOMEM);
	*commands = make_commlist(tokens);
	if (commands == NULL)
		return (ENOMEM);
	free_tokens(tokens);
	printf("parser done, lexer tokens freed\n");
	return (SUCCESS);
}
