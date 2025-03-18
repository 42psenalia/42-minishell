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
		printf("Type: %d, Value: [%s]\n", tokens->token_type, tokens->value);
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
			printf("\n  Output Redirect: >%s %s",
				node->outfile, node->append ? "(Append)" : "");
		printf("\n----------------\n");
		node = node->next;
	}
}

int	parser(char *line, t_shell_data *data, t_command **commands)
{
	t_tokens	*tokens;
	t_ast		*parsed_tokens;

	tokens = lexer(line);
	if (!tokens)
	{
		printf("Lexer failed!\n");
		return ;
	}
	print_tokens(tokens);
	while (tokens)
	{
		parsed_tokens = parse_tokens(tokens);
		if (!parsed_tokens)
		{
			printf("Parser failed!\n");
			return ;
		}
		print_ast(parsed_tokens);
		ft_lstadd_back(commands, parsed_tokens);
		// free_ast(parsed_tokens);
		tokens = tokens->next;
	}
	free_tokens(tokens);
}
