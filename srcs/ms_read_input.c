#include "../incs/minishell.h"
#include <stdio.h>

void    ms_read_input(t_ms *ms)
{
  free(ms->pronter);
  ms->pronter = ms_gnl_nj(0);
  ft_putstr_fd("Has introucido el siguiente comando: \n", 1);
  ft_putstr_fd(ms->pronter, 1);
  ft_putstr_fd("\n", 1);
  return ;
}
