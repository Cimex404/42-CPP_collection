# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 08:27:32 by jgraf             #+#    #+#              #
#    Updated: 2025/02/20 11:34:24 by jgraf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilation Rules
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11
NAME = replace
SRC = main.cpp replace_string.cpp
OBJ = $(SRC:.cpp=.o)

#	Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re