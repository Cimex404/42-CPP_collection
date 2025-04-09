# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 08:38:03 by jgraf             #+#    #+#              #
#    Updated: 2025/04/08 08:39:36 by jgraf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilation Rules
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17
NAME = functions
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

#	Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re