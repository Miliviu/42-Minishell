#ifndef MINISHELL_H
# define MINISHELL_H

# ifdef MS_LINUX

# endif

# ifdef MS_MAC

# endif

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

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
    char		    **paths;
    t_btl_node      *env;
	t_ms_options    options;
}   t_ms;

void    ms_kill_env_var(void *env_var);

/*  ./srcs/ms_utils.c   */
char *ms_gnl_nj(int fd);
char *ms_gnl_j(int fd);
void    ms_print_header(t_ms *ms);
void    ms_display_cursor(t_ms *ms);
void    ms_kill_split(char **split);
void    ms_kill_minishell(t_ms *ms);

/*  ./srcs/ms_init.c    */
void    ms_create_paths(t_ms *ms);
void    ms_read_env(t_ms *ms, char **env);
void    ms_init_minishell(t_ms *ms, int argc, char **args, char **env);

/*  ./srcs/ms_env_utils.c   */
void	ms_append_env_var(t_ms *ms, char *env);
void    ms_kill_env_var(void *env_var);
void    ms_print_env_var(void *env_var);

/*  ./srcs/ms_errors.c   */
void    ms_fatal_error(int code, t_ms *ms);

/*  ./srcs/ms_execute.c   */
void    ms_execute(t_ms *ms);

/*  ./srcs/ms_execute.c   */
void    ms_read_input(t_ms *ms);

#endif
