#include "../incs/minishell.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 *  MINISHELL EXIT CODES
 *
 *  0 - Sucess
 *  1 - Malloc error
 *
 * */

void    ms_fatal_error(int code)
{
    if (code == 1)
      ft_putstr_fd("Malloc error\n", 1);
    ft_putstr_fd("Exit with code: \n", 1);
    exit(code);
}

void    ms_init_minishell(t_ms *ms, int argc, char **args, char **env)
{
  return ;
}

int     ms_main_break(t_ms *ms)
{
    return (1);
    if (!ms->exit)
      ms_fatal_error(ms->exit);
    return (0);
}

void    ms_display_cursor(t_ms *ms)
{
    ft_putstr_fd(ANSI_COLOR_MAGENTA, 1);
    ft_putstr_fd("->/$ ", 1);
    ft_putstr_fd(ANSI_COLOR_RESET, 1);
}

void    ms_read_input(t_ms *ms)
{
  char  *pronter;

  pronter = ms_gnl_nj(0);
  while (!pronter)
    pronter = ms_gnl_nj(0);
  ft_putstr_fd("Has introucido el siguiente comando: \n", 1);
  ft_putstr_fd(pronter, 1);
  ft_putstr_fd("\n", 1);
  return ;
}

void    ms_execute(t_ms *ms)
{
    return ;
}

void    ms_print_header(t_ms *ms)
{
  ft_putstr_fd("/****************/\n", 1);
  ft_putstr_fd("/**  Minishell **/\n", 1);
  ft_putstr_fd("/****************/\n\n", 1);
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

void    ms_kill_minishell(t_ms *ms)
{
  return ;
}

void    ms_shot_minishell(t_ms *ms)
{
  return ;
}

int main(int argc, char **args, char **env)
{
  t_ms  ms;

  if (argc == 1)
  {
    ms_init_minishell(&ms, argc, args, env);
    ms_launch_minishell(&ms);
  }
  else
    ms_shot_minishell(&ms);
  ms_kill_minishell(&ms);
  return (0);
}
