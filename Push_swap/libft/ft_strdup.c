#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	size_t	str_len;
	size_t	i;

	i = 0;
	str_len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}	
