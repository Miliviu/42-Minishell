#include "../incs/minishell.h"

char *ms_gnl_nj(int fd)
{
  char  *line;
  int   len;

  line = get_next_line(fd);
  len = ft_strlen(line);
  if (line[--len] == '\n')
    line[len] = 0;
  return (line);
}

char *ms_gnl_j(int fd)
{
  return (get_next_line(fd));
}

void    ms_print_header(t_ms *ms)
{
  ft_putstr_fd("/****************/\n", 1);
  ft_putstr_fd("/**  Minishell **/\n", 1);
  ft_putstr_fd("/****************/\n\n", 1);
}

void    ms_display_cursor(t_ms *ms)
{
    ft_putstr_fd(ANSI_COLOR_MAGENTA, 1);
    ft_putstr_fd("->/$ ", 1);
    ft_putstr_fd(ANSI_COLOR_RESET, 1);
}

void    ms_kill_split(char **split)
{
    int i;

    if (!split)
		return ;
	i = -1;
    while (split[++i])
      free(split[i]);
    free(split);
}

void    ms_kill_minishell(t_ms *ms)
{
  btl_kill_tree(ms->env, &ms_kill_env_var);
  free(ms->pronter);
  ms_kill_split(ms->paths);
  return ;
}

