#include "../minishell.h"

void	sigint_handler(int signo)
{
	(void)signo;
	printf("\n");			// Move to a new line
	rl_on_new_line();		// Reset readline cursor
	rl_replace_line("", 0);	// Clear current input
	rl_redisplay();			// Show the new prompt
}

void	setup_signal(void)
{
	signal(SIGINT, sigint_handler);	// Handle Ctrl-C
	signal(SIGQUIT, SIG_IGN);		// Ignore Ctrl-backslash
}