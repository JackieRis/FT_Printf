# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnguyen- <tnguyen-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 17:54:04 by tnguyen-          #+#    #+#              #
#    Updated: 2021/12/09 18:55:14 by tnguyen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c \
	ft_putnbr_base.c ft_putnbr.c

OBJ	= ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra -I.

NAME = libftprintf.a

all: ${NAME}

%.o:%.c ft_printf.h
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all