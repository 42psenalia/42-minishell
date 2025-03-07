#include <errno.h>
#include "../libft/libft.h"
#include "parseline.h"

static int	process_line_into_tokens(char *line, t_list	**tokens, \
	t_shell_data *data)
{
	*tokens = tokenize_line(line);
	if (*tokens == NULL)
		return (ENOMEM);
	expand_tokens(tokens, data);
	if (*tokens == NULL)
		return (ENOMEM);
	return (1);
}

static int	check_syntax(t_token_list **tokens)
{
	if (!is_grammar_correct(*tokens))
	{
		ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
		ft_lstclear(tokens, free_token);
		return (EINVAL);
	}
	return (1);
}

int	parse_line(char *line, t_shell_data *data,
	t_command_list **commands)
{
	t_token_list	*tokens;
	int				ret;

	if (ft_strlen(line) == 0)
		return (0);
	else if (!is_quote_closed(line))
	{
		ft_putstr_fd("minishell: quote error\n", STDERR_FILENO);
		return (EINVAL);
	}
	ret = process_line_into_tokens(line, &tokens, data);
	if (ret != 1)
		return (ret);
	ret = check_syntax(&tokens);
	if (ret != 1)
		return (ret);
	*commands = create_command_list(tokens);
	ft_lstclear(&tokens, free_token);
	if (commands == NULL)
		return (ENOMEM);
	return (0);
}
