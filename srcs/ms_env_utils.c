#include "../incs/minishell.h"
#include <stdio.h>

void    ms_print_env_var(void *env_var)
{
    t_env_var   *aux;

    aux = env_var;
    ft_putstr_fd(aux->name,1);
    ft_putstr_fd("=",1);
    ft_putstr_fd(aux->content,1);
}


//Los frees de esta funcion no funcionan porque xd
void    ms_kill_env_var(void *env_var)
{
    t_env_var   *aux;

    aux = env_var;
    free(aux->name);
    free(aux->content);
    free(env_var);
}

/*
 *  MINISHELL EXIT CODES
 *
 *  0 - Sucess
 *  1 - Malloc error
 *
 * */

char	**ms_split_one(const char *s, char c)
{
	int	i;
	char	**split;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
	{
		split = malloc(8 * 2);
		split[0] = ft_strdup(s);
		split[1] = 0;
		return (split);
	}
	split = malloc(8 * 3);
	split[0] = malloc(i + 1);
	ft_strlcpy(split[0], s, i);
	split[1] = ft_strdup(s + i + 1);
	split[2] = 0;
	return (split);
}

void	ms_append_env_var(t_ms *ms, char *env)
{
    t_env_var   *env_var;
    char        **split;

	ft_putstr_fd("Appending env_var\n", 1);
	env_var = malloc(sizeof(t_env_var));
    	if (!env_var)
      		return ;
    	split = ms_split_one(env, '=');
    if (!split[1])
    {
      free(env_var);
      ms_kill_split(split);
      return ;
    }
    env_var->name = split[0];
    env_var->content = split[1];
    free(split);
    btl_insert_content_processed_value(&(ms->env), env_var, btl_string_score(env_var->name));
}
