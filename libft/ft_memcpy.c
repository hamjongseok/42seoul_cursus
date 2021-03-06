#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = dst;
	s2 = src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
