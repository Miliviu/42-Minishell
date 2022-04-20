/*	version: 2.0 */

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
int		btl_strncmp(const char *s1, const char *s2, unsigned int n);

/*  srcs/btl_modifiers.c    */
t_btl_node    *btl_new_node(void *content);
void    btl_insert_content_from_distance(t_btl_node **bt, void *content, int (*distance)(void *, void *), void (*kill_content)(void *));
void    btl_kill_tree(t_btl_node *bt, void (*kill_content)(void *));

/*  srcs/btl_search.c   */
t_btl_node      *btl_search_by_distance(t_btl_node **bt, void *content, int (*distance)(void *, void *));

/*  srcs/btl_scores.c   */
int  btl_str_distance(void *s1, void *s2);

#endif
