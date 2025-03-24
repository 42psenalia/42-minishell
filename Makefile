NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

BUILTIN_DIR = ./builtin
BUILTIN_SRCS = $(BUILTIN_DIR)/builtin_cd.c \
	$(BUILTIN_DIR)/builtin_echo.c \
	$(BUILTIN_DIR)/builtin_env.c \
	$(BUILTIN_DIR)/builtin_execute.c \
	$(BUILTIN_DIR)/builtin_exit.c \
	$(BUILTIN_DIR)/builtin_export.c \
	$(BUILTIN_DIR)/builtin_name.c \
	$(BUILTIN_DIR)/builtin_pwd.c \
	$(BUILTIN_DIR)/builtin_unset.c

ENVAR_DIR = ./envar
ENVAR_SRCS = $(ENVAR_DIR)/chkey_envar.c \
	$(ENVAR_DIR)/create_envar.c \
	$(ENVAR_DIR)/find_envnode.c \
	$(ENVAR_DIR)/form_envar.c \
	$(ENVAR_DIR)/free_envar.c \
	$(ENVAR_DIR)/get_envar.c \
	$(ENVAR_DIR)/print_del_envar.c \
	$(ENVAR_DIR)/set_envar.c

EXECUTE_DIR = ./execute
EXECUTE_SRCS = $(EXECUTE_DIR)/execute.c \
	$(EXECUTE_DIR)/execute_builtin.c \
	$(EXECUTE_DIR)/file_checkin.c \
	$(EXECUTE_DIR)/path_findjoin.c \
	$(EXECUTE_DIR)/processchild.c \
	$(EXECUTE_DIR)/processparent.c \
	$(EXECUTE_DIR)/processwait.c \
	$(EXECUTE_DIR)/redir_heredoc.c \
	$(EXECUTE_DIR)/redir_inout.c \
	$(EXECUTE_DIR)/setup_cmdlist.c

PARSER_DIR = ./parser
PARSER_SRCS = $(PARSER_DIR)/free.c \
	$(PARSER_DIR)/lexer.c \
	$(PARSER_DIR)/token.c \
	$(PARSER_DIR)/utils.c \
	$(PARSER_DIR)/parse_tokens.c \
	$(PARSER_DIR)/parse_utils.c \
    $(PARSER_DIR)/parser.c

SIGNALS_DIR = ./signals
SIGNALS_SRCS = $(SIGNALS_DIR)/signal_button.c

SRCS = main.c \
	shellstart.c \
	setsig.c \
	$(BUILTIN_SRCS) \
	$(ENVAR_SRCS) \
	$(EXECUTE_SRCS) \
	$(PARSER_SRCS) \
	$(SIGNALS_SRCS)

OBJS = $(SRCS:.c=.o)

INCLUDES = -I ./ -I $(LIBFT_DIR) -I $(BUILTIN_DIR) -I $(ENVAR_DIR) -I $(EXECUTE_DIR) -I $(PARSER_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re