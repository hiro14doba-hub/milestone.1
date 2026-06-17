# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 17:23:13 by dobashihiro       #+#    #+#              #
#    Updated: 2026/06/17 19:35:55 by hdobashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Werror -Wextra

CC = CC

RM = rm -f

SRC = get_next_line.c , get_next_line_utils.cc

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