#include "../incs/btl.h"

//Inserts content and gets value from evaluating the content with the function distance, this application must be injective to N
t_btl_node    *btl_new_node_content_processed_value(void *content, unsigned long long int value)
{
  t_btl_node    *result;

  if (!value)
    return (NULL);
  result = malloc(sizeof(t_btl_node));
  if (!result)
    return (NULL);
  result->content = content;
  result->value = value;
  result->right = NULL;
  result->left = NULL;
  return    result;
}

void    btl_insert_content_processed_value(t_btl_node **bt, void *content, unsigned long long int value)
{
  t_btl_node                *tmp;

  if (!(*bt))
  {
    tmp = btl_new_node_content_processed_value(content, value);
    *bt = tmp;
    return;
  }
  if (value == (*bt)->value)
    return ;
  if (value < (*bt)->value)
      btl_insert_content_processed_value(&((*bt)->left), content, value);
  else
      btl_insert_content_processed_value(&((*bt)->right), content, value);
}

void    btl_kill_tree(t_btl_node *bt, void (*kill_content)(void *))
{
    if (bt)
    {
        btl_kill_tree(bt->right, kill_content);
        btl_kill_tree(bt->left, kill_content);
        kill_content(bt->content);
    }
}
