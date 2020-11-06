#include <libft.h>

int main()
{

    t_tree *root;
    t_tree *left;
    t_tree *right;
    
    root = (t_tree*)ft_memalloc_fail(sizeof(*root));
    left = (t_tree*)ft_memalloc_fail(sizeof(*left));
    right = (t_tree*)ft_memalloc_fail(sizeof(*right));

    root->left = left;
    root->right = right;
    root->value = ft_strnew(255);
    root->value = ft_strncpy(root->value, "undeuxtroisquate", 250);

    return 0;
}
