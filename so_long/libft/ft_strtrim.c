#include "libft.h"

int	ft_get_first(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*c;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		c = ft_strchr(set, s1[i]);
		if (c == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_get_end(char const *s1, char const *set)
{
	int		len;
	char	*c;

	len = ft_strlen(s1) - 1;
	while (len >= 0)
	{
		c = ft_strchr(set, s1[len]);
		if (c == 0)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	char	*result;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = ft_get_first(s1, set);
	end = ft_get_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 1) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
