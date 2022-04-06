#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef MS_LINUX

# endif

# ifdef MS_MAC

# endif

# include "../libs/libft/libft.h"
# include "../libs/binary_trees_lib/incs/btl.h"
# include "../srcs/get_next_line/get_next_line.h"
typedef struct s_ms_options
{
  int   cursor_color;
} t_ms_options;

typedef struct  s_ms
{
  int           exit;
  t_ms_options  options;
}   t_ms;

#endif
