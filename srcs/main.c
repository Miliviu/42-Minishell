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

void    ms_kill_split(char **split)
{
    int i;

    i = -1;
    while (split[++i])
      free(split[i]);
    free(split);
}

void	ms_append_env_var(t_ms *ms, char *env)
{
    t_env_var   *env_var;
    char        **split;

	ft_putstr_fd("Appending env_var\n", 1);
    env_var = malloc(sizeof(t_env_var));
    if (!env_var)
      return ;
	ft_putstr_fd(env, 1);
	ft_putstr_fd("\n", 1);
    split = ft_split(env, '=');
	ft_putstr_fd("1\n", 1);
    env_var->name = split[0];
	ft_putstr_fd("2\n", 1);
    env_var->content = split[1];
	ft_putstr_fd("3\n", 1);
    if (!split[1])
    {
      ms_kill_split(split);
      return ;
    }
	ft_putstr_fd("4\n", 1);
    free(split);
	ft_putstr_fd("4.5\n", 1);
    btl_insert_content_processed_value(&(ms->env), env_var, btl_string_score(env_var->name));
	ft_putstr_fd("5\n", 1);
}

void    ms_create_paths(t_ms *ms)
{
  return ;
}

void	ms_read_env(t_ms *ms, char **env)
{
	ft_putstr_fd("Reading env\n", 1);
    ms->env = NULL;
    while (*env)
    {
		ms_append_env_var(ms, *env++);
    }
	ft_putstr_fd("Creating paths\n", 1);
    ms_create_paths(ms);
}

void    ms_init_minishell(t_ms *ms, int argc, char **args, char **env)
{
  ms->exit = 0;
  ms_read_env(ms, env);
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
  ms->pronter = pronter;
  return ;
}

void    ms_execute(t_ms *ms)
{
  if (!ft_strncmp("exit", ms->pronter, 5))
    ms_fatal_error(0);
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

void    ms_kill_env_var(void *env_var)
{
    t_env_var   *aux;

    aux = env_var;
    free(aux->name);
    free(aux->content);
    free(aux);
}

void    ms_kill_minishell(t_ms *ms)
{
  btl_kill_tree(ms->env, ms_kill_env_var);
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
    ft_putstr_fd("Init\n", 1);
    ms_init_minishell(&ms, argc, args, env);
    ft_putstr_fd("Launcher\n", 1);
    ms_launch_minishell(&ms);
  }
  else
    ms_shot_minishell(&ms);
  ms_kill_minishell(&ms);
  return (0);
}
