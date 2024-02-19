# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 15:45:27 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/03 14:40:28 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
INCS = ../submit srcs/includes/tyctest srcs/utils
REQUIRED_FLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCS))
CFLAGS = $(REQUIRED_FLAGS) $(DEBUG_CFLAGS)
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -g -fsanitize=address
endif

SRCS += $(shell find srcs/utils -name "*.c")
ifeq ($(MAKECMDGOALS), bonus)
	SRCS += $(shell find ../submit -name "*_bonus.c")
	SRCS += $(shell find srcs/bonus -name "*.c")
else
	SRCS += $(shell find ../submit -name "*.c" | grep -E -v ".*_bonus.c")
	SRCS += $(shell find srcs/mandatory -name "*.c")
endif

LIBS = $(shell find srcs/libs -name "*.a")

HEADERS = $(shell find ../ -name "*.h")

OBJS = $(SRCS:.c=.o)
CLEAN_FILES = bonus

all: $(NAME) $(BONUS_RULE)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(filter %.o,$^) $(LIBS)

bonus: $(SRCS:.c=.o) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(filter %.o,$^) $(LIBS)

debug: fclean bonus

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(CLEAN_FILES)
	$(RM) $(shell find .. -name "*.o")

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
