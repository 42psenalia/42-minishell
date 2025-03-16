/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:59:15 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:59:15 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "builtin.h"

t_exit_status	builtin_pwd(int argc, char **argv, t_shell_data *data)
{
	char	*path;

	(void) argc;
	(void) argv;
	path = get_envalue("PWD", data->env_var_list);
	if (path)
	{
		printf("%s\n", path);
		return (SUCCESS);
	}
	path = ft_getcwd();
	if (path)
	{
		printf("%s\n", path);
		free(path);
		return (SUCCESS);
	}
	path = ".";
	printf("%s\n", path);
	return (SUCCESS);
}
