#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!tmp)
		return (NULL);
	while (i < s1_len)
		tmp[i++] = *s1++;
	while (i < s2_len + s1_len)
		tmp[i++] = *s2++;
	tmp[i] = '\0';
	return (tmp);
}
