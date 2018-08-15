#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupriia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 21:31:26 by akupriia          #+#    #+#              #
#    Updated: 2017/12/03 21:31:26 by akupriia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRAM = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRCS = 	libft/ft_lstnew.c \
		libft/ft_lstpush.c \
		libft/ft_atoi_base.c \
		libft/ft_atoi.c \
		libft/ft_memcpy.c \
		libft/ft_memdel.c \
		libft/ft_memmove.c \
		libft/ft_strchr.c \
		libft/ft_strdel.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strnew.c \
		libft/ft_strsub.c \
		libft/ft_putendl_fd.c \
		libft/ft_putchar_fd.c \
		get_next_line.c \
		gradient.c \
		line_draw.c \
		map_rotate.c \
		move_x.c \
		move_y.c \
		open_read.c \
		parse_map.c \
		rotate.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(FRAM) $(SRCS) -o $(NAME)

.c.o.:
	$(CC) $(FLAGS) $(FRAM) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
