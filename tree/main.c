#include "libft.h"
#include <stdio.h>


int main()
{

    t_tree *root;
    t_tree *left;
    t_tree *right;

    int tab[1000] = {0};
    
    root = (t_tree*)ft_memalloc_fail(sizeof(*root));
    left = (t_tree*)ft_memalloc_fail(sizeof(*left));
    right = (t_tree*)ft_memalloc_fail(sizeof(*right));

    root->left = left;
    root->right = right;
    root->value = ft_strnew(255);
    root->value = ft_strncpy(root->value, "undeuxtroisquate", 250);

    return 0;
}

void insertNode(int value, t_tree *root)
{
    t_tree *new_node;

    new_node = (t_tree*)ft_memalloc_fail(sizeof(*new_node));
    new_node->left = NULL;
    new_node->right = NULL;

    if (value < root->value) {
        if (root->left == NULL) {
            root->left = new_node;
        } else {
            insertNode(value, root->left);
        }
    } else if (value > root->value) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            insertNode(value, root->right);
        }
    }
}
