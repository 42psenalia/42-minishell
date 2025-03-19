#include "parser.h"

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
		new_args[i] = node->argv[i];
		i++;
	}
	// Add new argument and NULL-terminate
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;
	// Free old args list and update node
	free(node->argv);
	node->argv = new_args;
}

t_ast	*create_ast_node(void)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof(t_ast));
	return (node);
}

// t_ast	*parse_tokens(t_tokens *tokens)
// {
//     t_ast	*head;
//     t_ast	*current;
//
//     head = create_ast_node();
//     if (!head)
//         return (NULL);
//     current = head;
//     while (tokens)
//     {
//         if (tokens->token_type == PIPE)
//         {
//             tokens = tokens->next; // Move to the next token after the pipe
//             if (!tokens) // If no tokens after the pipe, break
//                 break;
//             current->next = create_ast_node();
//             if (!current->next)
//             {
//                 free_ast(head); // Free the partially built AST
//                 return (NULL);
//             }
//             current = current->next; // Move to the new AST node
//         }
//         else if (tokens->token_type == REDIRIN || tokens->token_type == REDIROUT
//             || tokens->token_type == HEREDOC || tokens->token_type == APPEND)
//             handle_redirection(current, &tokens);
//         else
//         {
//             add_argument(current, tokens->value);
//             tokens = tokens->next;
//         }
//     }
//     return (head);
// }

static void	linksect(t_ast *main, t_ast *new)
{
	while (main->next)
		main = main->next;
	main->next = new;
}

t_ast	*parse_tokens(t_tokens *tokens)
{
	t_ast	*head;
	t_ast	*new;

	head = NULL;
	while (tokens)
	{
		if (tokens->token_type != PIPE)
			break ;
		new = create_ast_node();
		if (!new)
			return (NULL);
		handle_token(new, &tokens);
		if (!head)
			head = new;
		else
			linksect(head, new);
		tokens = tokens->next;
	}
	return (head);
}
