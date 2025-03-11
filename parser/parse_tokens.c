#include "../minishell.h"


void	handle_redirection(t_ast *node, t_tokens **tokens)
{
	t_tokens *current;

	if (!node || !tokens || !*tokens || !(*tokens)->next)
		return ;

	current = *tokens; // Save the redirection operator
	*tokens = (*tokens)->next; // Move to the filename token

	if (!*tokens) // No filename after redirection
		return ;

	if (current->token_type == REDIRIN)
		node->infile = ft_strdup((*tokens)->value);
	else if (current->token_type == REDIROUT)
		node->outfile = ft_strdup((*tokens)->value);
	else if (current->token_type == APPEND)
	{
		node->outfile = ft_strdup((*tokens)->value);
		node->append = 1;
	}
	else if (current->token_type == HEREDOC)
		node->infile = ft_strdup((*tokens)->value); // Placeholder for now

	*tokens = (*tokens)->next; // Move to the next token
}

void	add_argument(t_ast *node, char *arg)
{
	int		i;
	char	**new_args;

	if (!node || !arg)
		return ;
	
	// Count existing arguments
	i = 0;
	while (node->args && node->args[i])
		i++;

	// Allocate space for new argument list (+1 for new arg, +1 for NULL)
	new_args = malloc(sizeof(char *) * (i + 2));
	if (!new_args)
		return ;

	// Copy existing arguments
	i = 0;
	while (node->args && node->args[i])
	{
		new_args[i] = node->args[i];
		i++;
	}

	// Add new argument and NULL-terminate
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;

	// Free old args list and update node
	free(node->args);
	node->args = new_args;
}

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
