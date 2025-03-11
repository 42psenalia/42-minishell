#include "minishell.h"

t_ast	*create_ast_node(void)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->args = NULL;
	node->infile = NULL;
	node->outfile = NULL;
	node->append = 0;
	node->next = NULL;
	return (node);
}

t_ast	*parse_tokens(t_tokens *tokens)
{
	t_ast	*head;
	t_ast	*current;

	head = create_ast_node();
	current = head;
	while (tokens)
	{
		if (tokens->token_type == PIPE)
		{
			current->next = create_ast_node();
			current = current->next;
		}
		else if (tokens->token_type == REDIRIN || tokens->token_type == REDIROUT
			|| tokens->token_type == HEREDOC || tokens->token_type == APPEND)
			handle_redirection(current, &tokens);
		else
			add_argument(current, tokens->value);
		tokens = tokens->next;
	}
	return (head);
}
