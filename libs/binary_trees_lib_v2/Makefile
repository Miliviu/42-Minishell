NAME_LIB		= binary_tree_lib.a

T_2				= test_2

TESTS			= ${T_2}

INCS			= ./incs/binary_trees_lib.h

SRCS			= ./srcs/btl_utils.c \
				  ./srcs/btl_modifiers.c \
				  ./srcs/btl_search.c \
				  ./srcs/btl_printers.c \
				  ./srcs/btl_scores.c \

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Werror -Wextra

FSANITIZE		= -fsanitize=address -g3 -O0

AR				= ar rc

RM				= -rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME_LIB}: 	${INC} ${OBJS}
				${AR} ${NAME_LIB} ${OBJS}

${T_2}:			${INC} ${SRCS}
				${CC} -o ${T_2} ${SRCS} ./tests/btl_test2.c ${CFLAGS} ${FSANITIZE}

all:			${NAME_LIB}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME_LIB} ${TESTS}

re:				fclean all

.PHONY:			all clean fclean re
