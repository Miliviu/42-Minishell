#include "../incs/binary_trees_lib.h"

void    btl_print_in_order_value(t_btl_node *bt)
{
  if (bt)
  {
    btl_print_in_order_value(bt->left);
    btl_print_ull(bt->value);
    write(1, "\n", 1);
    btl_print_in_order_value(bt->right);
  }
}

void    btl_print_in_order_content(t_btl_node *bt, void (*print_content)(void *))
{
  if (bt)
  {
    btl_print_in_order_content(bt->left, print_content);
    print_content(bt->content);
    write(1, "\n", 1);
    btl_print_in_order_content(bt->right, print_content);
  }
}

static void    btl_print_in_order_content_value_aux(t_btl_node *bt, void (*print_content)(void *))
{
  if (bt)
  {
    btl_print_in_order_content_value_aux(bt->left, print_content);
    btl_print_ull(bt->value);
    write(1, "\t\t", 2);
    print_content(bt->content);
    write(1, "\n", 1);
    btl_print_in_order_content_value_aux(bt->right, print_content);
  }
}

void    btl_print_in_order_content_value(t_btl_node *bt, void (*print_content)(void *))
{
  write(1, "Value\t\tContent\n", 15);
  btl_print_in_order_content_value_aux(bt, print_content);
}
