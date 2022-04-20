#include "../incs/binary_trees_lib.h"

void    btl_print_in_order(t_btl_node *bt, void (*print_content)(void *))
{
  if (bt)
  {
    btl_print_in_order(bt->left, print_content);
    print_content(bt->content);
    write(1, "\n", 1);
    btl_print_in_order(bt->right, print_content);
  }
}
