#include "../incs/minishell.h"
#include <stdio.h>

void    ms_create_paths(t_ms *ms)
{
  return ;
}

void	ms_read_env(t_ms *ms, char **env)
{
  ms->env = NULL;
  while (*env)
    ms_append_env_var(ms, *env++);
  ms_create_paths(ms);
}

void    ms_init_minishell(t_ms *ms, int argc, char **args, char **env)
{
  ms->exit = 0;
  ms->pronter = 0;
  ft_putstr_fd("Reading env\n", 1);
  ms_read_env(ms, env);
  ft_putstr_fd("Creating paths\n", 1);
  ms_create_paths(ms);
  return ;
}
