#include "../incs/minishell.h"
#include <stdio.h>

void    ms_create_paths(t_ms *ms)
{
	char		**all_paths;
	t_env_var	*env_var;
	int			i;

	i = -1;
	env_var = btl_search_by_content(&(ms->env), &btl_string_score, "PATH")->content;
	all_paths = ft_split(env_var->content, ':');
	//
	while (all_paths[++i])
	{
		ft_putstr_fd(all_paths[i], 1);
		ft_putstr_fd("\n", 1);
	}
	//
	ms->paths = all_paths;
	return ;
}

void	ms_read_env(t_ms *ms, char **env)
{
  ms->env = NULL;
  while (*env)
    ms_append_env_var(ms, *env++);
}

void    ms_init_minishell(t_ms *ms, int argc, char **args, char **env)
{
  ms->exit = 0;
  ms->pronter = 0;
  ms->paths = 0;
  ft_putstr_fd("Reading env\n", 1);
  ms_read_env(ms, env);
  ft_putstr_fd("Creating paths\n", 1);
  //ms_create_paths(ms);
  return ;
}
