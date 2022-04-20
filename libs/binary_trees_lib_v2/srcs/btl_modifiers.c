#include "../incs/binary_trees_lib.h"

t_btl_node    *btl_new_node(void *content)
{
  t_btl_node    *result;

  result = malloc(sizeof(t_btl_node));
  if (!result)
    return (NULL);
  result->content = content;
  result->right = NULL;
  result->left = NULL;
  return    result;
}

void    btl_insert_content_from_distance(t_btl_node **bt, void *content, int (*distance)(void *, void *), void (*kill_content)(void *))
{
  t_btl_node                *tmp;
	int					dis;

  if (!(*bt))
  {
    tmp = btl_new_node(content);
    *bt = tmp;
    return;
  }
  dis = distance((*bt)->content, content);
  if (!dis)
  {
	  kill_content((*bt)->content);
	  (*bt)->content = content;
  }
  if (dis == 1)
      btl_insert_content_from_distance(&((*bt)->left), content, distance, kill_content);
  else
      btl_insert_content_from_distance(&((*bt)->right), content, distance, kill_content);
}

void    btl_kill_tree(t_btl_node *bt, void (*kill_content)(void *))
{
    if (bt)
    {
        btl_kill_tree(bt->right, kill_content);
        btl_kill_tree(bt->left, kill_content);
        kill_content(bt->content);
        free(bt);
    }
}
