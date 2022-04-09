NAME			= minishell

LIBS			= ./libs/libft/libft.a \
				  ./libs/binary_trees_lib/binary_tree_lib.a

INCS			= ./incs/minishell.h \
				  ./srcs/get_next_line/get_next_line.h \

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
				make -C ./libs/binary_trees_lib
				${CC} -o ${NAME} ${OBJS} ${LIBS}

${NAME}_LINUX: 	${INC} ${OBJS}
				make all -C ./libs/libft
				cp ./libs/libft/libft.a .
				make -C ./libs/libs/binary_trees_lib
				cp ./libs/binary_trees_lib .
				${CC} -o ${NAME} ${OBJS} ${LIBS}

all:			${NAME_LIB}

clean:
				make clean -C ./libs/libft
				make clean -C ./libs/binary_trees_lib
				${RM} ${OBJS}

fclean:			clean
				make fclean -C ./libs/libft
				make fclean -C ./libs/binary_trees_lib
				${RM} ${NAME} ${LIBS}

re:				fclean all

.PHONY:			all clean fclean re
