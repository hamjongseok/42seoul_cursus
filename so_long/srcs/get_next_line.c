/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:31:42 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/07 18:32:05 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#define BUFFER_SIZE 1

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

int	ft_find_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static char	*ft_make_backup(char **backup, int fd)
{
	char	*line;
	char	*new_backup;
	int		i;

	if (*backup[fd] == 0)
	{
		free(backup[fd]);
		backup[fd] = 0;
		return (0);
	}
	i = ft_find_char(backup[fd]);
	line = ft_substr(backup[fd], 0, i + 1);
	if (line == 0)
		return (0);
	new_backup = ft_substr(backup[fd], i + 1, ft_strlen(backup[fd]) - (i + 1));
	if (new_backup == 0)
	{
		free(line);
		return (0);
	}
	free(backup[fd]);
	backup[fd] = new_backup;
	return (line);
}

int	ft_get_backup(char **backup, int fd, char *buf)
{
	int	len;

	len = 1;
	while (len != 0 && !ft_strchr(backup[fd], '\n'))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			free(backup[fd]);
			return (0);
		}
		buf[len] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		free(backup[fd]);
		return (0);
	}
	if (!ft_get_backup(backup, fd, buf))
		return (0);
	free(buf);
	return (ft_make_backup(backup, fd));
}
