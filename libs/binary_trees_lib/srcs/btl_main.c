#include "../incs/btl.h"

#include <time.h>

unsigned long long int  btl_string_score(void *str)
{
  int                       i;
  unsigned char             *aux;
  unsigned long long int    result;

  result = 0;
  aux = str;
  i = -1;
  while (aux[++i])
    result = (unsigned int) aux[i] + 256 * result;
  return (result);
}

t_btl_node      *btl_search_by_value(t_btl_node **bt, unsigned long long int value)
{
  if (!value)
    return (NULL);
  if (!(*bt))
    return (NULL);
  if ((*bt)->value == value)
    return (*bt);
  else if ((*bt)->value > value)
    return (btl_search_by_value(&((*bt)->left), value));
  else
    return (btl_search_by_value(&((*bt)->right), value));
}

t_btl_node      *btl_search_by_content(t_btl_node **bt, unsigned long long int (*distance)(void *), void *content)
{
  return (btl_search_by_value(bt, distance(content)));
}

void kill_test(void *content)
{
  free(content);
}

int     btl_strlen(unsigned char *s)
{
  int   i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

void    print_string_test(void *str)
{
  unsigned char *aux;

  aux = str;
  write(1, aux, btl_strlen(aux));
}

char *test_create_random_string(int max_len, int len_set)
{
  char *str;
  int   n;

  str = malloc(max_len + 1);
  n = -1;
  while (++n < max_len)
    str[n] = (rand() % len_set + 'a') % 256;
  str[n] = 0;
  return (str);
}

int main(void)
{
  char  t1[100] = "100";
  char  t2[100] = "200";
  char  t3[100] = "300";
  char  t4[100] = "400";
  char  t5[100] = "500";
  t_btl_node    *bt;
  t_btl_node    *bt_aux;
  char  *aux_1;

  srand(time(NULL));
  bt = NULL;
  int   k = -1;
  while (++k < 10000)
  {
    aux_1 = test_create_random_string(5, 255);
    btl_insert_content_processed_value(&bt, aux_1, btl_string_score(aux_1));
  }
  //btl_print_in_order_value(bt);
  //btl_print_in_order_content(bt, &print_string_test);
  //btl_print_in_order_content_value(bt, &print_string_test);
  write (1, "\n\n", 2);
  k = -1;
  while (++k < 10000)
  {
    bt_aux = btl_search_by_content(&bt, &btl_string_score, test_create_random_string(5, 255));
    if (bt_aux)
    {
      print_string_test(bt_aux->content);
      write (1, "\n", 2);
    }
  }
  btl_kill_tree(bt, &kill_test);
  write(1, "FIN\n", 4);
  return (0);
}
