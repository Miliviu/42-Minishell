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
