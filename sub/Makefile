# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2022/03/14 20:37:18 by hoh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=push_swap
NAME_BONUS=checker
SRCSDIR=./
INCS=./
SRCS=main.c main_utils.c\
	 list_1.c list_2.c list_3.c\
	 ft_strtol.c utils.c\
	 process.c process_utils.c print.c
BONUS=main_checker.c main_utils.c print.c\
	  list_1.c list_2.c list_3.c\
	  ft_strtol.c utils.c\
	  get_next_line.c get_next_line_utils.c\
	  execute.c

OBJS=${SRCS:.c=.o}

OBJSBNS=${BONUS:.c=.o}

.PHONY: all clean fclean re

all : $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) -I$(INCS)

$(NAME_BONUS) : $(OBJSBNS)
	$(CC) $(CFLAGS) -g -o $(NAME_BONUS) $(OBJSBNS) -I$(INCS)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@ -I$(INCS)

clean:
	rm -f $(OBJS) $(OBJSBNS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all
