#include "parser.h"

char	*read_line(void)
{
	char	*new_line;

	printf(C"%s> "RST, ft_getcwd());

	new_line = readline("");
	if (!new_line)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (*new_line != '\0')
	{
		add_history(new_line);
	}
	printf("You entered: %s\n", new_line);
	return (new_line);
}

void	print_tokens(t_tokens *tokens)
{
	while (tokens)
	{
		printf("Type: %d, Value: [%s], Next-> %p\n", tokens->token_type, tokens->value, tokens->next);
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
			printf("\n  Input Redirect: <%s>", node->infile);
		if (node->outfile)
		{
			printf("\n  Output Redirect: >%s", node->outfile);
			if (node->token == APPEND)
				printf(" (Append)");
		}
		printf("\n----------------\n");
		node = node->next;
	}
}

static void	linkcommands(t_command *commands, t_ast *parsed)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return ;
	ft_bzero(new, sizeof(t_command));
	new->content = parsed;
	if (!commands)
		commands = new;
	else
	{
		while (commands->next)
			commands = commands->next;
		commands->next = new;
	}
}

// Currently not needing for t_exit_status but might be later
int	parser(char *line, t_command **commands)
{
	t_tokens	*tokens;
	t_ast		*parsed_tokens;

	if (ft_strlen(line) == 0)
		return (SUCCESS);
	tokens = lexer(line);
	if (!tokens)
	{
		ft_putstr_fd("Lexer failed!\n", STDERR_FILENO);
		return (EINVAL);
	}
	print_tokens(tokens);
	while (tokens)
	{
		parsed_tokens = parse_tokens(&tokens);
		if (!parsed_tokens)
		{
			printf("Parser failed!\n");
			return (ENOMEM);
		}
		print_ast(parsed_tokens);
		linkcommands(*commands, parsed_tokens);
		if (tokens)
			tokens = tokens->next;
	}
	free_tokens(tokens);
	printf("parser done, lexer tokens freed\n");
	return (SUCCESS);
}
