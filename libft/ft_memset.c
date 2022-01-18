#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (ptr);
}
