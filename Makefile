NAME			= minishell

LIBS			= ./libs/libft/libft.a

INCS			= ./incs/minishell.h \
				  ./srcs/get_next_line/get_next_line.h \

GNL				= 

SRCS			= ./srcs/get_next_line/get_next_line.c \
				./srcs/get_next_line/get_next_line_utils.c \
				./srcs/main.c \
				./srcs/ms_utils.c \

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -D MS_LINUX #-Wall -Werror -Wextra

RM				= -rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 		${INC} ${OBJS}
				make all -C ./libs/libft
				${CC} -o ${NAME} ${OBJS} ${LIBS}

${NAME}_LINUX: 	${INC} ${OBJS}
				make all -C ./libs/libft
				cp ./libs/libft/libft.a .
				${CC} -o ${NAME} ${OBJS}

all:			${NAME_LIB}

clean:
				make clean -C ./libs/libft
				${RM} ${OBJS}

fclean:			clean
				make fclean -C ./libs/libft
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
