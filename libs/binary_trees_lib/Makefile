NAME_LIB		= binary_tree_lib

LIBS			= 

INCS			= ./incs/binary_tree_lib.h

SRCS			= ./srcs/btl_main.c \
				./srcs/btl_printers.c \
				./srcs/btl_utils.c \
				./srcs/btl_modifiers.c \

OBJS			= ${SRCS:.c=.o}

CC				= cc

CFLAGS			= #-Wall -Werror -Wextra

AR				= ar rc

RM				= -rm -f

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME_LIB}: 	${INC} ${OBJS}
				${AR} ${NAME_LIB} ${OBJS}

test:			${INC} ${OBJS}
				${CC} -o ${NAME_LIB} ${OBJS} ${LIBS}

all:			${NAME_LIB}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME_LIB}

re:				fclean all

.PHONY:			all clean fclean re
