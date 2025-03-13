/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2025/03/13 14:53:59 by tanselbay1       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

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
		if (node->args)
		{
			i = 0;
			while (node->args[i])
			{
				printf("[%s] ", node->args[i]);
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

void	lsh_loop(void)
{
	char	*line;
	t_tokens *tokens;
	t_ast *parsed_tokens;

	// TODO: Read a line of input
	line = read_line();
	// TODO: Parse the line into arguments
	tokens = lexer(line);
	if (!tokens)
	{
		printf("Lexer failed!\n");
		return ;
	}
	print_tokens(tokens);
	
	parsed_tokens = parse_tokens(tokens);
	if (!parsed_tokens)
	{
		printf("Parser failed!\n");
		return ;
	}
	print_ast(parsed_tokens);
	
	// TODO: Execute the command
	// status = lsh_execute(args);
	
	// TODO: Free the line and arguments
	free_tokens(tokens);
    free_ast(parsed_tokens);
	free(line);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		printf(Y"Welcome to the 42bash!\n"RST);
		while (1)
		{
			lsh_loop();
		}
	}
	printf("\n");
	return (0);
}