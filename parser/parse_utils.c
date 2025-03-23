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

void	handle_redirection(t_ast *node, t_tokens **tokens)
{
	t_tokens	*current;

	if (!node || !tokens || !*tokens || !(*tokens)->next)
		return ;
	current = *tokens; // Save the redirection operator
	*tokens = (*tokens)->next; // Move to the filename token
	if (!*tokens) // No filename after redirection
		return ;
	node->token = current->token_type;
	if (current->token_type == REDIRIN)
		node->infile = ft_strdup((*tokens)->value);
	else if (current->token_type == REDIROUT || current->token_type == APPEND)
		node->outfile = ft_strdup((*tokens)->value);
	// else if (current->token_type == APPEND)
	// 	node->outfile = ft_strdup((*tokens)->value);
	else if (current->token_type == HEREDOC)
		node->infile = ft_strdup((*tokens)->value); // Keep the exit keyword
	*tokens = (*tokens)->next;
}

void	add_argument(t_ast *node, char *arg)
{
	int		i;
	char	**new_args;

	if (!node || !arg)
		return ;
	// Count existing arguments
	i = 0;
	while (node->argv && node->argv[i])
		i++;
	// Allocate space for new argument list (+1 for new arg, +1 for NULL)
	new_args = malloc(sizeof(char *) * (i + 2));
	if (!new_args)
		return ;
	// Copy existing arguments
	i = 0;
	while (node->argv && node->argv[i])
	{
		new_args[i] = ft_strdup(node->argv[i]);
		i++;
	}
	// Add new argument and NULL-terminate
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;
	int	t = 0;
	while (new_args[t])
	{
		printf("newarg[%d] = %s\n", t, new_args[t]);
		t++;
	}
	// Free old args list and update node
	if (node->argv)
		free_strarray(node->argv, i);
	node->argv = new_args;
}
