#include "../incs/binary_trees_lib.h"

t_btl_node      *btl_search_by_distance(t_btl_node **bt, void *content, int (*distance)(void *, void *))
{
  int	dis;
	
  if (!(*bt))
    return (NULL);
  dis = distance((*bt)->content, content);
  if (!dis)
    return (*bt);
  else if (dis == 1)
    return (btl_search_by_distance(&((*bt)->left), content, distance));
  else
    return (btl_search_by_distance(&((*bt)->right), content, distance));
}
