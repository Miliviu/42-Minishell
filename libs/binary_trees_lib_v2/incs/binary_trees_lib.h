#ifndef BTL_H
# define BTL_H

# include <stdlib.h>
# include <unistd.h>

typedef struct  s_btl_node
{
    void                    *content;
    struct s_btl_node       *left;
    struct s_btl_node       *right;
}   t_btl_node;

/*  srcs/btl_printers.c     */
void    btl_print_in_order(t_btl_node *bt, void (*print_content)(void *));

/*  srcs/btl_utils.c        */
int     btl_strlen(char *aux);

/*  srcs/btl_modifiers.c    */
t_btl_node    *btl_new_node(void *content);
void    btl_insert_content_from_score(t_btl_node **bt, void *content, int (*distance)(void *));
void    btl_kill_tree(t_btl_node *bt, void (*kill_content)(void *));

/*  srcs/btl_search.c   */
t_btl_node      *btl_search_by_content(t_btl_node **bt, void *content, int (*distance)(void *));

/*  srcs/btl_scores.c   */
unsigned long long int  btl_string_score(void *str);

#endif
