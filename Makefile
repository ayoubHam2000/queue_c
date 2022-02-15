# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:50:42 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/15 16:51:18 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = \
		q_clear.c \
		q_clone.c \
		q_dequeue.c \
		q_enqueue.c \
		q_init.c \
		main.c

#-Wall -Wextra -Werror
CFLAGS = -g -Wall -Wextra -Werror -I .
DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = queue

OBJ_DIR = OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

##################

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
