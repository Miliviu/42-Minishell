#include "../incs/minishell.h"
#include <stdio.h>

void    ms_execute(t_ms *ms)
{
	int	i;
	
	if (!ft_strncmp("exit", ms->pronter, 5))
    	ms_fatal_error(0, ms);
	if (!ft_strncmp("env", ms->pronter, 4))
		btl_print_in_order(ms->env, ms_print_env_var);
	if (!ft_strncmp("path", ms->pronter, 5))
	{
		i = -1;
		while (ms->paths[++i])
		{
			ft_putstr_fd(ms->paths[i], 1);
			ft_putstr_fd("\n", 1);
		}
	}
  return ;
}
