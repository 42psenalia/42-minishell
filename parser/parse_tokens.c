#include "parser.h"

t_ast	*create_ast_node(void)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_ast));
	return (node);
}

static void	linksect(t_ast *main, t_ast *new)
{
	while (main->next)
		main = main->next;
	main->next = new;
}

static void	get_argc(t_ast *command, t_tokens *tokens)
{
	while (tokens)
	{
		if (tokens->token_type == PIPE)
			break ;
		else if (tokens->token_type == WORD || tokens->token_type == DOLLAR \
			|| tokens->token_type == SQUOTE || tokens->token_type == DQUOTE)
			command->argc++;
		else if (tokens->token_type == REDIRIN || tokens->token_type == HEREDOC \
			|| tokens->token_type == REDIROUT || tokens->token_type == APPEND)
			tokens = tokens->next;
		tokens = tokens->next;
	}
}

t_ast	*parse_tokens(t_tokens **tokens, t_shell_data *data)
{
	t_ast	*head;
	t_ast	*new;

	head = NULL;
	while (*tokens)
	{
		// printf("current lexer %p, %d\n", *tokens, (*tokens)->token_type);
		if ((*tokens)->token_type == PIPE)
			break ;
		new = create_ast_node();
		if (!new)
			return (NULL);
		get_argc(new, *tokens);
		handle_token(new, tokens, data);
		if (!head)
			head = new;
		else
			linksect(head, new);
	}
	return (head);
}
