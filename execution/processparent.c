#include "execute.h"

void	ft_parentprocess(t_list *cmd_lst, int *prev_fd, t_execute *cmd)
{
	if (cmd_lst->next)
	{
		close(cmd->pipe_fds[1]);
		if (*prev_fd != -1)
			close(*prev_fd);
		*prev_fd = cmd->pipe_fds[0];
	}
	else if (*prev_fd != -1)
		close(*prev_fd);
}
