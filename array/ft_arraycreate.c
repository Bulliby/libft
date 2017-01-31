#include "libft.h"

t_array				*ft_arraycreate(void *content, size_t content_size)
{
	t_array			*ret;

	ret = ft_memalloc_fail(sizeof(t_array));	
	ret->content = ft_memalloc_fail(content_size);
	ft_memcpy(ret->content, content, content_size);
	ret->content_size = content_size;
	return (ret);
}
