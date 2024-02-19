/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:14:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 13:17:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlenchr(char const *s, char find)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != find)
		len++;
	return (len);
}

void	*free_manager(char **str1, t_pl **delone)
{
	t_pl	*tmp;

	if (str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (delone != NULL)
	{
		tmp = *delone;
		free_manager(&tmp->str, NULL);
		if (tmp->previous != NULL)
			tmp->previous->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->previous = tmp->previous;
		if (tmp->next != NULL)
			(*delone) = tmp->next;
		else if (tmp->previous != NULL)
			(*delone) = tmp->previous;
		else
			(*delone) = NULL;
		free(tmp);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, char find)
{
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (NULL);
}

char	*read_str(int fd)
{
	char	*buf;
	ssize_t	read_result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result < 0)
		return (free_manager(&buf, NULL));
	buf[read_result] = '\0';
	return (buf);
}

/**
 * pl_new:
 *     Create t_pl and return this. if fail, return NULL.
 * pl_add_front:
 *     Add target2 before target1.
 *     Rewrite target1 with target2 pointer.
 * pl_clear:
 *     Clear all lists taht include target1.
 */
void	*pool_list_utils(t_pl **target1, t_pl **target2, int fd, t_lo ope)
{
	t_pl	*tmp;

	if (ope == pl_new)
	{
		tmp = (t_pl *)malloc(sizeof(t_pl));
		if (tmp == NULL)
			return (NULL);
		*tmp = (t_pl){.fd = fd, .next = NULL, .previous = NULL, .str = NULL};
		return (tmp);
	}
	else if (ope == pl_add_front)
	{
		while (*target1 != NULL && (*target1)->previous != NULL)
			(*target1) = (*target1)->previous;
		(*target1)->previous = (*target2);
		(*target2)->next = (*target1);
		(*target1) = (*target2);
	}
	else if (ope == pl_clear)
	{
		while (*target1 != NULL)
			free_manager(NULL, target1);
	}
	return (NULL);
}
