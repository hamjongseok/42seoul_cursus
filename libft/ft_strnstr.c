#include "libft.h"

int	ft_is_true(const char *h, const char *n, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if ((h[i] != n[j]) || !len || !h[i])
			return (0);
		i++;
		j++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	i = 0;
	if (!*n)
		return ((char *)h);
	while (len && h[i])
	{
		if (ft_is_true(h, n, i, len))
			return ((char *)&(h[i]));
		i++;
		len--;
	}
	return (0);
}
