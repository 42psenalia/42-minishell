#include <errno.h>
#include "shellstart.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "libft/libft.h"
#include "builtin/builtin.h"

#define RED "\1\033[31m\2"
#define UNDERLINE_RED "\1\033[4;31m\2"
#define RESET "\1\033[0m\2"

static char	*get_prompt(t_shell_data *data)
{
	char	*path;
	char	*prompt;

	path = get_envalue("PWD", data->env_var_list);
	if (path == NULL)
		path = ".";
	prompt = va_strjoin(10, \
		"mini", RED, "s", RESET, UNDERLINE_RED, "hell", RESET, \
		":", path, "$ ");
	if (prompt == NULL)
		return (NULL);
	return (prompt);
}

static char	*get_line(t_shell_data *data)
{
	char	*prompt;
	char	*line;

	prompt = get_prompt(data);
	if (prompt == NULL)
	{
		data->exit_status = ENOMEM;
		return (NULL);
	}
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*read_line(t_shell_data *data)
{
	char	*line;

	line = get_line(data);
	if (line == NULL)
		return (NULL);
	if (ft_strlen(line) > 0)
		add_history(line);
	return (line);
}
