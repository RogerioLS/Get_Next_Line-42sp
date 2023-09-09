# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 22:11:31 by roglopes          #+#    #+#              #
#    Updated: 2023/09/09 15:11:27 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./sources/library/get_next_line.a
NAME_B		= ./sources_bonus/library/get_next_line_bonus.a

SOURCES		= get_next_line.c     \
			get_next_line_utils.c \

SOURCES_B	= get_next_line_bonus.c     \
			get_next_line_utils_bonus.c \

INCLUDES	= ./sources/includes/
INCLUDES_B	= ./sources_bonus/includes/

SOURCES		:= $(addprefix ./sources/,$(SOURCES))
OBJECTS		= $(SOURCES:./sources/%.c=./objects/%.o)

SOURCES_B	:= $(addprefix ./sources_bonus/,$(SOURCES_B))
OBJECTS_B	= $(SOURCES_B:./sources_bonus/%.c=./objects/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJECTS)

./objects/%.o: ./sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)
	ar rcs $(NAME) $@

bonus: $(NAME_B)

$(NAME_B): $(OBJECTS_B)

./objects/%.o: ./sources_bonus/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_B)
	ar rcs $(NAME_B) $@

clean:
	$(RM) $(OBJECTS) $(OBJECTS_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus