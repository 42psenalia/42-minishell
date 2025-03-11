#include "libft.h"
#include "shellstart.h"
#include <termios.h>

t_shell_data	*makeshell(char **env)
{
	t_shell_data	*data;

	// (void) argc;
	// (void) argv;
	data = malloc(sizeof(t_shell_data));
	if (data == NULL)
		return (NULL);
	data->envar_list = form_envar(env);
	if (data->envar_list == NULL)
	{
		free(data);
		return (NULL);
	}
	data->exit_status = EXIT_SUCCESS;
	return (data);
}

void	freeshell(t_shell_data *data)
{
	free_envar_list(&data->envar_list);
	free(data);
}

void	silent_cntl(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return ;
	term.c_lflag != ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	restore_terminal_settings(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return ;
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

t_shell_data	*initialize(int argc, char **argv, char **env)
{
	t_shell_data	*data;

	silent_cntl();
	setupsignal();
	data = makeshell(env);
	if (data == NULL)
		return (NULL);
	return (data);
}
