/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psenalia <psenalia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:25 by psenalia          #+#    #+#             */
/*   Updated: 2025/03/23 18:57:44 by psenalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "parser/parser.h"
# include "builtin/builtin.h"
# include "envar/envar.h"
# include "execute/execute.h"
# include "shellstart.h"
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

// typedef enum e_token_type
// {
// 	SQUOTE,
// 	DQUOTE,
// 	DOLLAR,
// 	PIPE,
// 	REDIRIN,
// 	REDIROUT,
// 	HEREDOC,
// 	APPEND,
// 	WORD
// }	t_token_type;

// typedef struct s_tokens
// {
// 	t_token_type	token_type;
// 	char			*value;
// 	struct s_tokens	*next;
// }					t_tokens;

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
// 	char			*in_file;
// 	char			*out_file;
// 	char			*command;
// 	int				fd_in;
// 	int				fd_out;
// 	pid_t			pipid;
// 	struct s_pipseq	*prev;
// 	struct s_pipseq	*next;
// }					t_pipseq;

// typedef t_list	t_command;
// typedef struct s_ast
// {
// 	char			**args;		// Command + arguments
// 	char			*infile;	// Input redirection file
// 	char			*outfile;	// Output redirection file
// 	int				append;		// 1 if ">>", 0 otherwise
// 	struct s_ast	*next;		// Next command in a pipeline
// }	t_ast;


// MAIN.C
int	main(int ac, char **av, char **env);


// // --LEXER--
//
// // UTILS.C
// char	*getcwd(void);
// int		is_special(char c);
// int		is_space(char c);
// int		ft_strcmp(const char *s1, const char *s2);
//
// // TOKEN.C
// void	add_token(t_tokens **head, t_token_type type, char *value);
// t_token_type	get_token_type(char *str);
//
// // LEXER.C
// char	*extract_quoted(char **input, char quote_type);
// t_tokens	*lexer(char *input);
// char	*extract_operator(char **input);
//
// // --PARSER--
//
// // PARSE_TOKENS.C
// void	handle_redirection(t_ast *node, t_tokens **tokens);
// void	add_argument(t_ast *node, char *arg);
// t_ast	*create_ast_node(void);
// t_ast	*parse_tokens(t_tokens *tokens);
//
// // PARSE_UTILS.C
// void	handle_pipe(t_ast **current, t_ast **head, t_tokens **tokens);
// void	handle_token(t_ast *current, t_tokens **tokens);
//
// // --FREE--
//
// // FREE.C
// void	free_ast(t_ast *node);
// void	free_tokens(t_tokens *tokens);

#endif