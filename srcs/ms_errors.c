#include "../incs/minishell.h"
#include <stdio.h>

/*
 *  MINISHELL EXIT CODES
 *
 *  0 - Sucess
 *  1 - Malloc error
 *
 * */

void    ms_fatal_error(int code, t_ms *ms)
{
    if (code == 1)
      ft_putstr_fd("Malloc error\n", 1);
    ft_putstr_fd("Exit with code: \n", 1);
    if (ms)
      ms_kill_minishell(ms);
    exit(code);
}
