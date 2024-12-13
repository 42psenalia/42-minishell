/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2024/12/13 16:45:20 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

char	*read_line(void)
{
	char	*new_line;

	printf("Welcome to the 42bash!\n");
	new_line = readline("> ");
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

void	lsh_loop(void)
{
	char	*line;

	// char **args;
	// int status;
	// TODO: Read a line of input
	line = read_line();
	free(line);
	// TODO: Parse the line into arguments
	// args = lsh_split_line(line);
	// TODO: Execute the command
	// status = lsh_execute(args);
	// TODO: Free the line and arguments
	// free(args);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		lsh_loop();
	}
	printf("\n");
	return (0);
}