#include "../minishell.h"

void	free_tokens(t_tokens *tokens)
{
    t_tokens *tmp;

    while (tokens)
    {
        tmp = tokens;
        tokens = tokens->next;
        free(tmp->value);
        free(tmp);
    }
}

void	free_ast(t_ast *node)
{
    t_ast *tmp;
    int i;

    while (node)
    {
        tmp = node;
        node = node->next;
        if (tmp->args)
        {
            i = 0;
            while (tmp->args[i])
            {
                free(tmp->args[i]);
                i++;
            }
            free(tmp->args);
        }
        if (tmp->infile)
            free(tmp->infile);
        if (tmp->outfile)
            free(tmp->outfile);
        free(tmp);
    }
}