#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				result;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	result = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{	
			result = str1[i] - str2[i];
			return (result);
		}
		i++;
	}
	return (result);
}
