/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:58:39 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/04 18:32:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_pl	*pool;
	char		*line;
	char		*leftovers;

	if (get_target_pl(&pool, fd) == NULL)
		return (NULL);
	leftovers = NULL;
	line = _get_next_line(&(pool->str), fd, &leftovers);
	free_manager(&(pool->str), NULL);
	pool->str = leftovers;
	if (line == NULL)
		free_manager(NULL, &pool);
	return (line);
}

t_pl	*get_target_pl(t_pl **pool, int fd)
{
	t_pl	*target;

	target = *pool;
	while (target != NULL && target->previous != NULL)
		target = target->previous;
	while (target != NULL && target->fd != fd)
		target = target->next;
	if (target == NULL)
	{
		target = pool_list_utils(NULL, NULL, fd, pl_new);
		if (target == NULL)
			return (NULL);
		if (*pool != NULL && target != NULL)
			pool_list_utils(pool, &target, 0, pl_add_front);
	}
	*pool = target;
	if (target->str == NULL)
		target->str = ft_substrchr("", '\0');
	if (target->str == NULL)
		return (free_manager(NULL, pool));
	return (target);
}

/**
 * If read eof, free `str` and assign NULL.
 */
char	*_get_next_line(char **str, int fd, char **leftovers)
{
	char	*joined;
	char	*line;
	int		is_eof;

	is_eof = 0;
	while (ft_strchr(*str, '\n') == NULL && is_eof == 0)
	{
		joined = ft_strjoin_fd(*str, fd, &is_eof);
		if (joined == NULL || ft_strlenchr(joined, '\0') == 0)
			return (free_manager(&joined, NULL));
		free_manager(str, NULL);
		*str = joined;
	}
	line = ft_substrchr(*str, '\n');
	if (line == NULL)
		return (NULL);
	if (is_eof != 0)
	{
		*leftovers = NULL;
		return (line);
	}
	*leftovers = ft_substrchr((*str) + ft_strlenchr(line, '\0'), '\0');
	if (*leftovers == NULL)
		return (free_manager(&line, NULL));
	return (line);
}

char	*ft_strjoin_fd(char *left, int fd, int *is_eof)
{
	size_t	count;
	size_t	index;
	char	*right;
	char	*right_iter;
	char	*joined;

	right = read_str(fd);
	if (right == NULL)
		return (NULL);
	count = ft_strlenchr(left, '\0') + ft_strlenchr(right, '\0') + 1;
	joined = (char *)malloc(sizeof(char) * count);
	if (joined == NULL)
		return (free_manager(&right, NULL));
	index = 0;
	while (*left != '\0')
		joined[index++] = *(left++);
	right_iter = right;
	while (*right_iter != '\0')
		joined[index++] = *(right_iter++);
	joined[index] = '\0';
	*is_eof = (ft_strlenchr(right, '\0') == 0);
	free_manager(&right, NULL);
	return (joined);
}

char	*ft_substrchr(char const *str, char sep)
{
	char	*sub;
	char	*find;
	size_t	index;
	size_t	len;

	len = 0;
	find = ft_strchr(str, sep);
	if (find != NULL)
		len = (size_t)(find - str) + 1;
	else
		len = ft_strlenchr(str, '\0');
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	index = 0;
	while (str[index] != '\0' && index < len)
	{
		sub[index] = str[index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
