/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processchild.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:00:48 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/16 13:00:48 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <unistd.h>

static void	do_redirs(t_list *cmd_lst, t_execute *cmd, int *prev_fd)
{
	if (cmd_lst->next)
	{
		dup2(cmd->pipe_fds[1], STDOUT_FILENO);
		close(cmd->pipe_fds[1]);
		close(cmd->pipe_fds[0]);
	}
	if (*prev_fd != -1)
	{
		dup2(*prev_fd, STDIN_FILENO);
		close(*prev_fd);
	}
	if (cmd->command->token)
		handle_redir_input_output(cmd_lst);
}

static void	free_cmd_lst_if_exit(t_list **cmd_lst_first, t_ast *command)
{
	t_list		*next;
	t_execute	*cmd;

	while (*cmd_lst_first)
	{
		next = (*cmd_lst_first)->next;
		cmd = (*cmd_lst_first)->content;
		if (cmd->command == command)
			ft_lstdelone(*cmd_lst_first, free);
		else
			ft_lstdelone(*cmd_lst_first, free_execute_command);
		*cmd_lst_first = next;
	}
}

static int	execute(char **cmd, t_list *env_var_list)
{
	char	*path;
	char	**envp;

	if (!cmd || !cmd[0])
		return (SUCCESS);
	if (ft_strchr(cmd[0], '/') && access(cmd[0], X_OK) == SUCCESS)
		path = ft_strdup(cmd[0]);
	else
		path = find_path("PATH", env_var_list, cmd[0]);
	printf("got path %s\n", path);
	if (path == NULL)
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		return (ISSUE_PATH);
	}
	envp = get_envarray(env_var_list);
	if (envp == NULL)
		return (ERROR);
	printf("got to execve\n");
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_strarray(envp, 0);
		return (ISSUE_PATH);
	}
	return (SUCCESS);
}

int	ft_childprocess(t_list **cmd_lst_first, t_list *cmd_lst,
		int *prev_fd, t_shell_data *envp)
{
	t_execute	*cmd;
	t_ast		*command;

	printf("children process\n");
	cmd = cmd_lst->content;
	command = cmd->command;
	if (check_infiles(command) == ERROR)
		return (ERROR);
	printf("checkfile passed\n");
	do_redirs(cmd_lst, cmd, prev_fd);
	printf("redirects done\n");
	if (builtin_check(command->argv[0]))
	{
		printf("detect builtin command\n");
		if (ft_strcmp(command->argv[0], "exit") == 0)
			free_cmd_lst_if_exit(cmd_lst_first, command);
		return (builtin_execute(command, envp));
	}
	printf("not builtin command\n");
	return (execute(command->argv, envp->envar_list));
}
