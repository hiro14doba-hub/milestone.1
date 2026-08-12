# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 17:23:13 by dobashihiro       #+#    #+#              #
#    Updated: 2026/08/09 23:08:11 by hdobashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f
NAME = get_next_line.a
SRC = get_next_line.c  get_next_line_utils.c

OBJS = $(SRC:.c=.o)

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