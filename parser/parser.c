#include "parser.h"

char	*read_line(void)
{
    char	*new_line;
    char	*prompt;
    char	*cwd;

    cwd = ft_getcwd(); // Get the current working directory
    prompt = ft_strjoin(C, cwd); // Use cwd for the prompt
    free(cwd); // Free the memory allocated by ft_getcwd
    new_line = ft_strjoin(prompt, "> " RST);
    free(prompt); // Free the memory allocated by ft_strjoin

    new_line = readline(new_line);
    if (!new_line)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    if (*new_line != '\0')
    {
        add_history(new_line);
    }
    return (new_line);
}

void	print_tokens(t_tokens *tokens)
{
	while (tokens)
	{
		printf("Type: %d, Value: [%s], Next-> %p\n", \
			tokens->token_type, tokens->value, tokens->next);
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

static t_command	*make_commlist(t_tokens *tokens, t_shell_data *data)
{
	t_command	*commands;
	t_ast		*parsed_tokens;

	// printf("making commlist\n");
	commands = NULL;
	while (tokens)
	{
		parsed_tokens = parse_tokens(&tokens, data);
		if (!parsed_tokens)
			return (NULL);
		print_ast(parsed_tokens);
		linkcommands(&commands, parsed_tokens);
		// printf("commands linked\n");
		if (tokens)
			tokens = tokens->next;
	}
	t_command	*temp;
	temp = commands;
	while (temp)
	{
		printf("Command: %p, next-> %p\n", temp->content, temp->next);
		temp = temp->next;
	}
	return (commands);
}

// Currently not needing t_shell_data for t_exit_status but might be later
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
	*commands = make_commlist(tokens, data);
	if (commands == NULL)
		return (ENOMEM);
	free_tokens(tokens);
	printf("parser done, lexer tokens freed\n");
	return (SUCCESS);
}
