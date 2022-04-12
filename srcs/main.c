#include "../incs/minishell.h"
#include <stdio.h>

int     ms_main_break(t_ms *ms)
{
    return (1);
    if (!ms->exit)
      ms_fatal_error(ms->exit, ms);
    return (0);
}

void    ms_launch_minishell(t_ms *ms)
{
  ms_print_header(ms);
  while (ms_main_break(ms))
  {
    ms_display_cursor(ms);
    ms_read_input(ms);
    ms_execute(ms);
  }
}

int main(int argc, char **args, char **env)
{
  t_ms  ms;

  if (argc == 1)
  {
    ft_putstr_fd("Init\n", 1);
    ms_init_minishell(&ms, argc, args, env);
    ft_putstr_fd("Launcher\n", 1);
    ms_launch_minishell(&ms);
  }
  ms_kill_minishell(&ms);
  //system("leaks ./minishell");
  return (0);
}
