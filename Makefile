# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2022/04/21 22:30:23 by hoh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=so_long
NAME_BONUS=so_long_bonus
MLXDIR=./mlx
SRCSDIR=./srcs/
INCSDIR=./incs/
SRCSBNSDIR=./srcs_bns/
SRCS_NAME= main.c arg_check.c map_check.c\
	  character_draw.c draw.c menu.c events.c\
	  move_1.c move_2.c search.c touch.c\
	  free.c ft_mlx.c get_next_line.c get_next_line_utils.c utils.c\
	  init.c location.c parsing.c reset.c
SRCS=$(addprefix $(SRCSDIR), $(SRCS_NAME))

BONUS_NAME=${SRCS_NAME:.c=_bonus.c}

BONUS=$(addprefix $(SRCSBNSDIR), $(BONUS_NAME))

OBJS=${SRCS:.c=.o}

OBJSBNS=${BONUS:.c=.o}

.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCSDIR) -I$(MLXDIR)

all : $(NAME) $(NAME_BONUS)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLXDIR) -I$(INCSDIR) -lmlx -framework OpenGL -framework Appkit

$(NAME_BONUS) : $(OBJSBNS)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJSBNS) -L$(MLXDIR) -I$(INCSDIR) -lmlx -framework OpenGL -framework Appkit

clean:
	make -C $(MLXDIR) clean
	rm -f $(OBJS) $(OBJSBNS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all
