/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/29 16:45:21 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include "../builtin/builtin.h"
// # include "../execute/execute.h"
# include "../shellstart.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>


// ANSI Color codes for terminal output formatting:
// Y - Yellow
// G - Green
// C - Cyan
// RED - Red
// RST - Reset to default color

# define Y "\033[1;33m"
# define G "\033[1;32m"
# define C "\033[1;36m"
# define RED "\033[1;31m"
# define RST "\033[0m"

typedef enum e_token_type
{
	SQUOTE = 39,
	DQUOTE = 34,
	DOLLAR = 36,
	PIPE = 124,
	REDIRIN = 60,
	REDIROUT = 62,
	HEREDOC = 61,
	APPEND = 63,
	WORD = 69
}	t_token_type;

typedef struct s_tokens
{
	t_token_type	token_type;
	char			*value;
	struct s_tokens	*next;
}					t_tokens;

// typedef struct s_tokencount
// {
// 	int				squote;
// 	int				dquote;
// 	int				dollar;
// 	int				pipe;
// 	int				redirin;
// 	int				redirout;
// 	int				heredoc;
// 	int				append;
// }	t_tokencount;

// typedef struct s_pipseq
// {
// 	// char			*in_file;
// 	// char			*out_file;
// 	// char			*command;
// 	int				fd_in;
// 	int				fd_out;
// 	pid_t			pipid;
// 	// struct s_pipseq	*prev;
// 	struct s_pipseq	*next;
// }					t_pipseq;

typedef t_list	t_command;

typedef struct s_ast
{
	int				argc;		// Count of argv
	char			**argv;		// Command + arguments
	struct s_tokens	*infile;	// Input redirection file
	struct s_tokens	*outfile;	// Output redirection file
	struct s_ast	*next;		// Next command in a pipeline
}	t_ast;


// MAIN.C
char	*read_line(void);

// --LEXER--

// UTILS.C
char	*ft_getcwd(void);
int		is_special(char c);
int		is_space(char c);

// TOKEN.C
void	add_token(t_tokens **head, t_token_type type, char *value);
t_token_type	get_token_type(char *str);

// LEXER.C
t_tokens	*lexer(char *input);
char	*extract_word(char **input);
char	*extract_quoted(char **input, char quote_type, t_token_type *type);
char	*extract_operator(char **input);

// --PARSER--
int		parser(char *line, t_command **commands, t_shell_data *data);

// PARSE_TOKENS.C
t_ast	*create_ast_node(void);
t_ast	*parse_tokens(t_tokens **tokens, t_shell_data *data);

// PARSE_UTILS.C
// void	handle_pipe(t_ast **current, t_ast **head, t_tokens **tokens);
void	handle_token(t_ast *current, t_tokens **tokens, t_shell_data *data);
void	handle_redirection(t_ast *node, t_tokens **tokens);
void	add_argument(t_ast *node, char *arg);

void	handle_dollar(t_tokens *token, t_shell_data *data);

// --FREE--

// FREE.C
void	free_ast(t_ast *node);
void	free_tokens(t_tokens *tokens);

#endif