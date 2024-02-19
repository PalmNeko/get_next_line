
NAME = test
NAME_BONUS = test_bonus
SRCDIR = ..
INCLUDES = $(dir $(shell find $(SRCDIR) -name "*.h"))
SRCS = $(shell find $(SRCDIR) -name "*.c" ! -name "*_bonus.c" -type f | xargs)
OBJS = $(SRCS:.c=.o)
DEPENDS = $(OBJS:.o=.d)
SRCS_BONUS = $(shell find $(SRCDIR) -name "*_bonus.c" -o -name "*_union.c" -type f | xargs)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
DEPENDS_BONUS = $(OBJS_BONUS:.o=.d)
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP $(addprefix -I , $(INCLUDES))

.PHONY: all
all: $(NAME) $(NAME_BONUS)

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

$(NAME): $(OBJS)
	echo 'test'
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPENDS)
	rm -f $(OBJS_BONUS) $(DEPENDS_BONUS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

.PHONY: re
re: fclean all

.PHONY: debug
debug: CFLAGS += -g -fsanitize=integer -fsanitize=address # -fsanitize=leak
debug: re
