#include "../incs/btl.h"

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
