# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2022/04/28 12:44:39 by hoh              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=so_long
NAME_BONUS=so_long_bonus
MLXDIR=./mlx
LIBDIR=../libohw
LIBINCSDIR=../libohw/includes
SRCSDIR=./srcs/
INCSDIR=./incs/
SRCSBNSDIR=./srcs_bns/
SRCS_NAME= main.c arg_check.c map_check.c\
	character_draw.c draw.c menu.c events.c\
	move_1.c move_2.c move_3.c search.c touch.c\
	free.c ft_mlx.c get_next_line.c get_next_line_utils.c utils.c\
	init.c location.c parsing.c reset.c\
	key_press.c key_release.c destroy_enemy.c
SRCS=$(addprefix $(SRCSDIR), $(SRCS_NAME))

BONUS_NAME=${SRCS_NAME:.c=_bonus.c}

BONUS=$(addprefix $(SRCSBNSDIR), $(BONUS_NAME))

OBJS=${SRCS:.c=.o}

OBJSBNS=${BONUS:.c=.o}

.PHONY: all bonus clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCSDIR) -I$(MLXDIR)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLXDIR) -L$(LIBDIR) -I$(INCSDIR) -lmlx -lohw -framework OpenGL -framework Appkit

$(NAME_BONUS) : $(OBJSBNS)
	make -C $(MLXDIR)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJSBNS) -L$(MLXDIR) -L$(LIBDIR) -I$(INCSDIR) -lmlx -lohw -framework OpenGL -framework Appkit

clean:
	make -C $(MLXDIR) clean
	make -C $(LIBDIR) clean
	rm -f $(OBJS) $(OBJSBNS)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all
