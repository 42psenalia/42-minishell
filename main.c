/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselbay1 <tanselbay1@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2025/03/11 12:45:40 by tanselbay1       ###   ########.fr       */
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

void	lsh_loop(void)
{
	char	*line;
	t_tokens *tokens;

	// TODO: Read a line of input
	line = read_line();
	// TODO: Parse the line into arguments
	tokens = lexer(line);
	print_tokens(tokens);
	
	// args = lsh_split_line(line);
	// TODO: Execute the command
	// status = lsh_execute(args);
	// TODO: Free the line and arguments
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