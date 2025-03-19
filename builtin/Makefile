NAME = builtin.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

OBJS_DIR = .builtin_objs

HEADERS = builtin.h

SRCS = builtin_cd.c builtin_echo.c builtin_env.c builtin_execute.c \
	builtin_exit.c builtin_export.c builtin_name.c builtin_pwd.c \
	builtin_unset.c

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
