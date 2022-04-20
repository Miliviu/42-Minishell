#ifndef BTL_H
# define BTL_H

# include <stdlib.h>
# include <unistd.h>

typedef struct  s_btl_node
{
    unsigned long long int  value;
    void                    *content;
    struct s_btl_node       *left;
    struct s_btl_node       *right;
}   t_btl_node;

/*  srcs/btl_printers.c     */
void    btl_print_in_order_value(t_btl_node *bt);
void    btl_print_in_order_content(t_btl_node *bt, void (*print_content)(void *));
void    btl_print_in_order_content_value(t_btl_node *bt, void (*print_content)(void *));

/*  srcs/btl_utils.c        */
void    btl_print_ull(unsigned long long int n);
int     btl_strlen(char *aux);

/*  srcs/btl_modifiers.c    */
t_btl_node    *btl_new_node_content_processed_value(void *content, unsigned long long int value);
void    btl_insert_content_processed_value(t_btl_node **bt, void *content, unsigned long long int value);
void    btl_kill_tree(t_btl_node *bt, void (*kill_content)(void *));

/*  srcs/btl_search.c   */
t_btl_node      *btl_search_by_value(t_btl_node **bt, unsigned long long int value);
t_btl_node      *btl_search_by_content(t_btl_node **bt, unsigned long long int (*distance)(void *), void *content);

/*  srcs/btl_scores.c   */
unsigned long long int  btl_string_score(void *str);

#endif
