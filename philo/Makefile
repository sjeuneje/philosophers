NAME = philo

SRCS = src/main.c src/errors.c src/init.c src/utils.c src/threads.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

INC = -I incl/

C_THREADS = -lpthread -g3

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:	${NAME}

$(NAME): ${OBJS}
		$(CC) ${CFLAGS} $(INC) $(C_THREADS) $(OBJS) -o $(NAME)

exe:	${OBJS}
		$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
		${RM} ${OBJS}
clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

PHONY:	re flcean clean all