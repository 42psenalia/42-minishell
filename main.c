/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:19 by tanselbay1        #+#    #+#             */
/*   Updated: 2025/03/22 16:19:03 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_signal;

static void	detect_line(char *line, t_shell_data *data)
{
	t_command	*commands;
	int			progress;

	if (ft_strlen(line) == 0)
	{
		data->exit_status = SUCCESS;
		return ;
	}
	commands = NULL;
	progress = parser(line, &commands);
	if (progress == EINVAL || commands == NULL)
	{
		printf("error: no entry found\n");
		data->exit_status = ENOENT;
		return ;
	}
	else if (progress == ENOMEM)
		builtin_exit(NULL, data);
	printf("entering execution\n");
	data->exit_status = main_execute(&commands, data);
}

// char	*read_line(void)
// {
// 	char	*new_line;
//
// 	printf(C"%s> "RST, ft_getcwd());
// 	new_line = readline("");
// 	if (!new_line)
// 	{
// 		fprintf(stderr, "lsh: allocation error\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (*new_line != '\0')
// 	{
// 		add_history(new_line);
// 	}
// 	printf("You entered: %s\n", new_line);
// 	return (new_line);
// }

// void	print_tokens(t_tokens *tokens)
// {
// 	while (tokens)
// 	{
// 		printf("Type: %d, Value: [%s]\n", tokens->token_type, tokens->value);
// 		tokens = tokens->next;
// 	}
// }

// void	print_ast(t_ast *node)
// {
// 	int	i;
//
// 	while (node)
// 	{
// 		printf("Command: ");
// 		if (node->args)
// 		{
// 			i = 0;
// 			while (node->args[i])
// 			{
// 				printf("[%s] ", node->args[i]);
// 				i++;
// 			}
// 		}
// 		else
// 			printf("(None)");
// 		if (node->infile)
// 			printf("\n  Input Redirect: <%s>", node->infile);
// 		if (node->outfile)
// 			printf("\n  Output Redirect: >%s %s",
// 				node->outfile, node->append ? "(Append)" : "");
// 		printf("\n----------------\n");
// 		node = node->next;
// 	}
// }

// int	parser(char *line, t_shell_data *data, t_command **commands)
// {
// 	t_tokens	*tokens;
// 	t_ast		*parsed_tokens;
//
// 	tokens = lexer(line);
// 	if (!tokens)
// 	{
// 		printf("Lexer failed!\n");
// 		return ;
// 	}
// 	print_tokens(tokens);
// 	while (tokens)
// 	{
// 		parsed_tokens = parse_tokens(tokens);
// 		if (!parsed_tokens)
// 		{
// 			printf("Parser failed!\n");
// 			return ;
// 		}
// 		print_ast(parsed_tokens);
// 		ft_lstadd_back(commands, parsed_tokens);
// 		// free_ast(parsed_tokens);
// 		tokens = tokens->next;
// 	}
// 	free_tokens(tokens);
// }

static void	lsh_loop(t_shell_data *data)
{
	char		*line;

	g_signal = READMODE;
	line = read_line();
	if (g_signal != READMODE)
		data->exit_status = g_signal;
	if (line == NULL)
	{
		if (errno == ENOMEM)
			data->exit_status = ENOMEM;
		else
			printf("exit\n");
		builtin_exit(NULL, data);
	}
	g_signal = EXECUTEMODE;
	detect_line(line, data);
	free(line);
}

int	main(int ac, char **av, char **env)
{
	t_shell_data	*data;
	int				i;

	data = initialize(ac, av, env);
	if (data == NULL)
		return (EXIT_FAILURE);
	(void)av;
	if (ac >= 1)
		printf(Y"Welcome to the 42bash!\n"RST);
	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			detect_line(av[i], data);
			i++;
		}
	}
	lsh_loop(data);
}
