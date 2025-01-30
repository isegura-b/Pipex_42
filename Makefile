# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 15:31:55 by isegura-          #+#    #+#              #
#    Updated: 2025/01/14 15:37:37 by isegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
OBJ_DIR = ./obj
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(SRC_DIR)/pipex.c \
      $(SRC_DIR)/pipex_utils.c \

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

INCLUDE = $(LIBFT_DIR)/libft.h \
		  $(SRC_DIR)/pipex.h

all: libs $(NAME)

libs:
		make -C $(LIBFT_DIR)

$(NAME): 	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus:	libs $(BONUS_OBJ)
		$(CC) $(CFLAGS) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) Makefile
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) -C $(LIBFT_DIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
