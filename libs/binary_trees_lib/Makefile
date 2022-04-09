NAME_LIB		= binary_tree_lib.a

T_1				= test_1

TESTS			= ${T_1}

INCS			= ./incs/binary_trees_lib.h

SRCS			= ./srcs/btl_utils.c ./srcs/btl_modifiers.c ./srcs/btl_search.c ./srcs/btl_printers.c ./srcs/btl_scores.c ./tests/btl_test1.c

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Werror -Wextra

AR				= ar rc

RM				= -rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME_LIB}: 	${INC} ${OBJS}
				${AR} ${NAME_LIB} ${OBJS}

${T_1}:			${INC} ${OBJS}
				${CC} -o ${T_1} ${OBJS}

all:			${NAME_LIB}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME_LIB} ${TESTS}

re:				fclean all

.PHONY:			all clean fclean re
