NAME = execute.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

OBJS_DIR = .execute_objs

HEADERS = execute.h

SRCS = execute.c execute_builtin.c file_checkin.c path_findjoin.c \
	redir_inout.c redir_heredoc.c setup_cmdlist.c \
	processchild.c processparent.c processwait.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

.PHONY: all clean fclean re
