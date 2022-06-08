NAME = philo

SRCS = src/init_params.c src/main.c\
		utils/errors_handler.c utils/ft_atoi.c utils/ft_isdigit.c\

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

INC = -I inc/

C_THREADS = -lpthread

C_O = \
    if [ ! -e  "objs" ]; then \
    mkdir objs; \
    fi

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