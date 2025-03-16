NAME = envar.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

OBJS_DIR = .envar_objs
SUB_OBJS_DIRS = $(addprefix $(OBJS_DIR)/, list single)

HEADERS = envar.h

SRCS = chkey_envar.c create_envar.c \
	find_envnode.c form_envar.c free_envar.c \
	get_envar.c print_del_envar.c set_envar.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(SUB_OBJS_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SUB_OBJS_DIRS):
	mkdir -p $@

.PHONY: all clean fclean re
