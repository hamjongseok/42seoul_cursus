#include "libft.h"

static char	**ft_malloc_error(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
	str = NULL;
	return (NULL);
}

void	ft_cpy(char **result, char const *head, int a, int len)
{
	int	b;
	int	i;

	b = 0;
	i = 0;
	while (b < len)
	{
		result[a][b] = head[i];
		b++;
		i++;
	}
	result[a][b] = 0;
}

char	**ft_make_arr(char **result, char c, char const *s, int i)
{
	int			len;
	int			a;
	char const	*head;

	a = 0;
	while (i--)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		head = s;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		result[a] = (char *)malloc(sizeof(char) * (len + 1));
		if (result[a] == NULL)
			return (ft_malloc_error(result));
		ft_cpy(result, head, a, len);
		a++;
	}
	result[a] = 0;
	return (result);
}

int	ft_col_size(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		len;

	if (!s)
		return (NULL);
	len = ft_col_size(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	result = ft_make_arr(result, c, s, len);
	if (!result)
		return (NULL);
	len -= 1;
	return (result);
}
