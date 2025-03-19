/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:58:26 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 12:58:26 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "builtin.h"

static char	*get_path(int argc, char **argv, t_list *list)
{
	char	*path;

	if (argc == 1)
	{
		path = get_envalue("HOME", list);
		if (path == NULL)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
			return (NULL);
		}
	}
	else
		path = argv[1];
	return (path);
}

static bool	update_shell_variable(char *old_path, t_shell_data *data)
{
	char			*current_path;
	t_envar_list	*set_node;

	set_node = setenvar("OLDPWD", old_path, &data->envar_list);
	if (set_node == NULL)
		return (false);
	current_path = ft_getcwd();
	if (current_path == NULL)
		return (false);
	set_node = setenvar("PWD", current_path, &data->envar_list);
	free(current_path);
	if (set_node == NULL)
		return (false);
	return (true);
}

static bool	change_directory(char *old_path, char *new_path,
				t_shell_data *data)
{
	if (chdir(new_path) != SUCCESS)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(new_path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (false);
	}
	if (!update_shell_variable(old_path, data))
		return (false);
	return (true);
}

t_exit_status	builtin_cd(int argc, char **argv, t_shell_data *data)
{
	char	*old_path;
	char	*new_path;

	if (argc >= 3)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (ERROR);
	}
	old_path = get_envalue("PWD", data->envar_list);
	new_path = get_path(argc, argv, data->envar_list);
	if (new_path == NULL)
		return (ERROR);
	if (!change_directory(old_path, new_path, data))
		return (ERROR);
	return (SUCCESS);
}
