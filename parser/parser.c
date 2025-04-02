/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:55:16 by tbayrakt          #+#    #+#             */
/*   Updated: 2025/04/02 14:43:26 by psenalia         ###   ########.fr       */
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
		ft_putstr_fd("minishell: lsh: allocation error\n", STDERR_FILENO);
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

	commands = NULL;
	while (tokens)
	{
		parsed_tokens = parse_tokens(&tokens);
		if (!parsed_tokens)
			return (NULL);
		linkcommands(&commands, parsed_tokens);
		if (tokens)
			tokens = tokens->next;
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

int	parser(char *line, t_command **commands, t_shell_data *data)
{
	t_tokens	*tokens;
	t_tokens	*reprise;

	if (ft_strlen(line) == 0)
		return (SUCCESS);
	tokens = NULL;
	if (lexer(line, &tokens) == EINVAL || !tokens)
	{
		if (!tokens)
			ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		return (EINVAL);
	}
	if (convertdollar(tokens, data) == ERROR)
		return (ENOMEM);
	reprise = reprisetokens(tokens);
	if (!reprise)
		return (ENOMEM);
	free_tokens(tokens);
	*commands = make_commlist(reprise);
	if (commands == NULL)
		return (ENOMEM);
	free_tokens(reprise);
	return (SUCCESS);
}
