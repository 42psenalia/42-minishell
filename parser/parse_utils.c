#include "parser.h"

void	handle_pipe(t_ast **current, t_ast **head, t_tokens **tokens)
{
	*tokens = (*tokens)->next; // Move to the next token after the pipe
	if (!*tokens) // If no tokens after the pipe, return
		return ;
	(*current)->next = create_ast_node();
	if (!(*current)->next)
	{
		free_ast(*head); // Free the partially built AST
		*head = NULL;
		return ;
	}
	*current = (*current)->next; // Move to the new AST node
}

void	handle_token(t_ast *current, t_tokens **tokens)
{
	if ((*tokens)->token_type == REDIRIN || (*tokens)->token_type == REDIROUT
		|| (*tokens)->token_type == HEREDOC || (*tokens)->token_type == APPEND)
	{
		handle_redirection(current, tokens);
		return ;
	}
	else
	{
		while (*tokens && (*tokens)->token_type == WORD)
		{
			add_argument(current, (*tokens)->value);
			*tokens = (*tokens)->next;
		}
	}
}
