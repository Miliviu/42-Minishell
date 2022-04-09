#include "../incs/binary_trees_lib.h"

#include <time.h>

void    kill_test(void *a)
{
  a++;
  a--;
  return ;
}

void    print_string_test(void *str)
{
  unsigned char *aux;

  aux = str;
  write(1, aux, btl_strlen((char *)aux));
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
/*
  char  t1[100] = "100";
  char  t2[100] = "200";
  char  t3[100] = "300";
  char  t4[100] = "400";
  char  t5[100] = "500";
  */
  t_btl_node    *bt;
  t_btl_node    *bt_aux;
  char  *aux_1;

  srand(time(NULL));
  bt = NULL;
  int   k = -1;
  while (++k < 100)
  {
    aux_1 = test_create_random_string(5, 26);
    btl_insert_content_processed_value(&bt, aux_1, btl_string_score(aux_1));
  }
  btl_print_in_order_value(bt);
  btl_print_in_order_content(bt, &print_string_test);
  btl_print_in_order_content_value(bt, &print_string_test);
  write (1, "\n\n", 2);
  write(1, "COINCIDENCIAS\n", 14);
  k = -1;
  while (++k < 1000000)
  {
    bt_aux = btl_search_by_content(&bt, &btl_string_score, test_create_random_string(5, 26));
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
