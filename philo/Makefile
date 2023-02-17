# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 14:32:38 by cfontain          #+#    #+#              #
#    Updated: 2022/11/02 11:56:52 by cfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= 	main.c\
				build_arg.c\
				build_philo.c\
				check_end.c\
				eating.c\
				print.c\
				routine.c\
				sleeping.c\
				thinking.c\
				utils.c\
				take_fork.c\
				parsing.c\
				dead.c

OBJS		= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS		= -Wall -Wextra -Werror -g -I includes/

all		: ${NAME}

%.o: %.c
		  @${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}		: ${OBJS}
		  @echo "\033[34m----Compiling----"
		  @${CC} ${FLAGS} ${OBJS} -L/usr/include  -lpthread -L -lm -o ${NAME}
		  @echo "OK"

clean		:
		  @echo "\033[31m----Cleaning objects----"
		  @${RM} ${OBJS}
		  @echo "OK"

fclean		: clean
		  @echo "\033[33m----Cleaning all----"
		  @${RM} ${NAME}
		  @echo "OK"

re		: fclean all

.PHONY		: all clean fclean re
