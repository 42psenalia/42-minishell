#include "parser.h"

void	free_tokens(t_tokens *tokens)
{
	t_tokens	*temp;

	while (tokens)
	{
		temp = tokens->next;
		free(tokens->value); // Ensure value is dynamically allocated
		free(tokens);
		tokens = temp;
	}
}

void	free_ast(t_ast *node)
{
	t_ast	*tmp;
	int		i;

	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->argv)
		{
			i = 0;
			while (tmp->argv[i])
			{
				free(tmp->argv[i]);
				i++;
			}
			free(tmp->argv);
		}
		if (tmp->infile)
			free(tmp->infile);
		if (tmp->outfile)
			free(tmp->outfile);
		free(tmp);
	}
}
