# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 13:54:33 by mcochin           #+#    #+#              #
#    Updated: 2023/03/28 13:41:49 by mcochin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp

SRCS =	main.cpp	\
		Fixed.cpp	\
		Point.cpp	\
		bsp.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -g -Werror -Wextra -Wall -std=c++98
RM = rm -f
MAKE = make -C

all : $(NAME)

$(NAME) : $(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@ $(RM) $(OBJS) $(NAME)

fclean : clean
	@ $(RM) $(NAME)

re : fclean $(NAME)

f : fclean

.PHONY: all fclean re clean
