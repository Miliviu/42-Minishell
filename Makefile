NAME			= minishell

LIBS			= ./libs/libft/libft.a \
				  ./libs/binary_trees_lib/binary_tree_lib.a

INCS			= ./incs/minishell.h \
				  ./srcs/get_next_line/get_next_line.h \

SRCS			= ./srcs/get_next_line/get_next_line.c \
				./srcs/get_next_line/get_next_line_utils.c \
				./srcs/main.c \
				./srcs/ms_utils.c \
				./srcs/ms_init.c \
				./srcs/ms_env_utils.c \
				./srcs/ms_errors.c \
				./srcs/ms_execute.c \
				./srcs/ms_read_input.c \


OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -D MS_LINUX #-Wall -Werror -Wextra

FSANITIZE		= -fsanitize=address -g3 -O0 ${CFLAGS}

RM				= -rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 		${INC} ${OBJS}
				make all -C ./libs/libft
				make -C ./libs/binary_trees_lib
				${CC} -o ${NAME} ${OBJS} ${LIBS}

${NAME}_linux: 	${INC} ${OBJS}
				make all -C ./libs/libft
				cp ./libs/libft/libft.a .
				make -C ./libs/libs/binary_trees_lib
				cp ./libs/binary_trees_lib .
				${CC} -o ${NAME}_linux ${OBJS} ${LIBS}

${NAME}_leaks: 			${INC} ${SRCS}
				make all -C ./libs/libft
				make -C ./libs/binary_trees_lib
				${CC} -o ${NAME}_leaks ${SRCS} ${LIBS} ${FSANITIZE}


all:			${NAME_LIB}

clean:
				make clean -C ./libs/libft
				make clean -C ./libs/binary_trees_lib
				${RM} ${OBJS}

fclean:			clean
				make fclean -C ./libs/libft
				make fclean -C ./libs/binary_trees_lib
				${RM} ${NAME} ${NAME}_linux ${NAME}_leaks ${LIBS} leaks_output.file

re:				fclean all

.PHONY:			all clean fclean re
