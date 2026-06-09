# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dobashihiromunin <dobashihiromunin@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/09 16:42:25 by dobashihiro       #+#    #+#              #
#    Updated: 2026/06/09 17:05:41 by dobashihiro      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putnbr_unsigned.c ft_putnbr.c ft_putptr.c ft_putstr.c print_check.c put_hexlow.c put_hexup.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar crs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re