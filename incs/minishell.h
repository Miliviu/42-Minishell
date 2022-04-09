#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef MS_LINUX

# endif

# ifdef MS_MAC

# endif

# include "../libs/libft/libft.h"
# include "../libs/binary_trees_lib/incs/binary_trees_lib.h"
# include "../srcs/get_next_line/get_next_line.h"

typedef struct s_ms_options
{
  int   cursor_color;
} t_ms_options;

typedef struct  s_env_var
{
    char    *name;
    char    *content;
}   t_env_var;

typedef struct  s_ms
{
	int	            exit;
  	char            *pronter;
    t_btl_node      *env;
	t_ms_options    options;
}   t_ms;

/*  ./srcs/ms_utils.c   */
char *ms_gnl_nj(int fd);
char *ms_gnl_j(int fd);

#endif
