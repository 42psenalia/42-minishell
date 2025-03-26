/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:58:36 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:36 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "builtin.h"

static bool	is_n_flag(char *str)
{
	if (*str != '-')
		return (false);
	str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}

static void	apply_options(int argc, char **argv, int *i, bool *put_newline)
{
	while (*i < argc)
	{
		if (!is_n_flag(argv[*i]))
			break ;
		*put_newline = false;
		(*i)++;
	}
}

static void	print_arguments(int argc, char **argv, int *i, t_shell_data *data)
{
	while (*i < argc)
	{
		if (get_token_type(argv[*i]) == DOLLAR)
			handle_dollar(argv[*i], data);
		else
			printf("%s", argv[*i]);
		if (*i < argc - 1)
			printf(" ");
		(*i)++;
	}
}

t_exit_status	builtin_echo(int argc, char **argv, t_shell_data *data)
{
	bool	put_newline;
	int		i;

	(void) data;
	put_newline = true;
	i = 1;
	if (i < argc)
	{
		apply_options(argc, argv, &i, &put_newline);
		print_arguments(argc, argv, &i, data);
	}
	if (put_newline)
		printf("\n");
	return (SUCCESS);
}
