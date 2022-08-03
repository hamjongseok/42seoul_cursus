/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamjongseog <hamjongseog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:37:46 by hamjongseog       #+#    #+#             */
/*   Updated: 2022/06/10 00:11:23 by hamjongseog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

char	*ft_strdup_x_newline(char *s)
{
	char	*str;
	int		size;
	int		i;

	str = NULL;
	size = ft_strlen(s);
	i = 0;
	str = malloc(size + 1);
	if (!(str))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strcpy_x_newline(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_x_newline(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	str = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_x_newline(s2));
	else if (s2 == NULL)
		return (ft_strdup_x_newline(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len);
	if (!(str))
		return (NULL);
	ft_strcpy_x_newline(str, s1, s1_len + 1);
	ft_strcpy_x_newline(str + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (str);
}
