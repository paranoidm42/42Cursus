# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 10:56:30 by ccur              #+#    #+#              #
#    Updated: 2023/08/17 10:56:31 by ccur             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   minitalk

SERVER			=	server
SERVER_SRC		=	server.c


CLIENT			=	client
CLIENT_SRC		=	client.c


UTILS_SRC		=	utils.c

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER) :
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)


$(CLIENT) :
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)

clean :
	$(RM) $(SERVER) $(CLIENT)

fclean :
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY: all clean fclean re
