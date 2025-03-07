#include "execute.h"

int	check_infiles(t_list *file)
{
	t_token	*redir;

	while (file)
	{
		redir = (t_token *)file->content;
		if (redir->type == INFILE)
		{
			file = file->next;
			redir = (t_token *)file->content;
			if (redir->type == WORD)
			{
				if (access(redir->str, R_OK) != SUCCESS
					|| (access(redir->str, R_OK | W_OK) != SUCCESS))
				{
					perror(redir->str);
					return (ERROR);
				}
			}
		}
		file = file->next;
	}
	return (SUCCESS);
}
