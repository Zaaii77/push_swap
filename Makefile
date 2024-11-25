# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 13:23:46 by lowatell          #+#    #+#              #
#    Updated: 2024/11/25 20:09:01 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR = srcs
INCS_DIR = inc
OBJS_DIR = objs

NAME = push_swap

SRCS =	main.c node_utils.c push.c rev_rotate.c rotate.c swap.c utils.c \
	utils2.c utils3.c algo.c parsing.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GREEN = \033[32m

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make clean -C libft
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Objects files have been deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)push_swap has been deleted."

re: fclean all

$(NAME): $(OBJS)
	@make -C libft/
	@mv libft/libft.a $(OBJS_DIR)/
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_DIR)/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) has been compiled."

.PHONY: all clean fclean re

