# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 16:28:46 by ccur              #+#    #+#              #
#    Updated: 2023/07/05 16:40:35 by ccur             ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)

shared:
    $(CC) -shared -o libft.so $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME) libft.so

re: fclean all

.PHONY: all clean fclean re shared

