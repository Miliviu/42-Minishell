#include "../incs/minishell.h"
#include <stdio.h>

void    ms_execute(t_ms *ms)
{
  if (!ft_strncmp("exit", ms->pronter, 5))
    ms_fatal_error(0, ms);
  if (!ft_strncmp("env", ms->pronter, 4))
    btl_print_in_order_content(ms->env, ms_print_env_var);;
  return ;
}
