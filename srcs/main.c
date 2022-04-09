#include "../incs/minishell.h"
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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

    write(1, "hola\n", 5);
    aux = env_var;
    ft_putstr_fd(aux->name, 1);
    free(aux->name);
    free(aux->content);
    free(env_var);
}

void    ms_kill_minishell(t_ms *ms)
{
  btl_kill_tree(ms->env, &ms_kill_env_var);
  free(ms->pronter);
  return ;
}

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
    split = ft_split(env, '=');
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

int     ms_main_break(t_ms *ms)
{
    return (1);
    if (!ms->exit)
      ms_fatal_error(ms->exit, ms);
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
  free(ms->pronter);
  ms->pronter = ms_gnl_nj(0);
  ft_putstr_fd("Has introucido el siguiente comando: \n", 1);
  ft_putstr_fd(ms->pronter, 1);
  ft_putstr_fd("\n", 1);
  return ;
}

void    ms_execute(t_ms *ms)
{
  if (!ft_strncmp("exit", ms->pronter, 5))
    ms_fatal_error(0, ms);
  if (!ft_strncmp("env", ms->pronter, 4))
    btl_print_in_order_content(ms->env, ms_print_env_var);;
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
