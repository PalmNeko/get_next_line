/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:49:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 12:38:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char	*gnl_cut(t_gnl_mem *mem);
void	*gnl_memmove(void *dest, const void *src, size_t n);
int		gnl_read_line(int fd, t_gnl_mem *mem);

char	*get_next_line(int fd)
{
	static t_gnl_mem_lst	*keep_node;
	t_gnl_mem_lst			*use_node;
	char					*line;

	use_node = gnl_get_node(&keep_node, fd);
	if (use_node == NULL)
	{
		use_node = gnl_new_node(fd);
		if (use_node == NULL)
			return (NULL);
		gnl_add_node(&keep_node, use_node);
	}
	line = gnl_get_next_line_mem(use_node->mem, fd);
	if (line == NULL)
		gnl_del_node(&use_node);
	keep_node = use_node;
	return (line);
}

char	*gnl_get_next_line_mem(t_gnl_mem *mem, int fd)
{
	ssize_t				result;
	char				*line;

	result = 0;
	if (mem->line_cnt == 0)
		result = 1;
	while (result > 0 && mem->line_cnt == 0)
		result = gnl_read_line(fd, mem);
	if (result == -1)
		return (NULL);
	line = gnl_cut(mem);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*gnl_cut(t_gnl_mem *mem)
{
	char	*line;
	char	*line_ptr;
	size_t	line_index;
	size_t	cp_len;

	if (mem->size == 0)
		return (NULL);
	line_ptr = mem->data;
	line_index = 0;
	while (mem->data[line_index] != '\n' && line_index < mem->size - 1)
		line_index++;
	line_ptr = mem->data + line_index;
	line_index = line_ptr - mem->data;
	cp_len = line_index + 1;
	line = (char *)malloc(sizeof(char) * (cp_len + 1));
	if (line == NULL)
		return (NULL);
	gnl_memmove(line, mem->data, cp_len);
	line[cp_len] = '\0';
	gnl_memmove(mem->data, line_ptr + 1, (mem->size - cp_len));
	mem->size = (mem->size - cp_len);
	mem->line_cnt -= 1;
	return (line);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				index;

	d = dest;
	s = src;
	if (d < s)
	{
		index = 0;
		while (index < n)
		{
			d[index] = s[index];
			index++;
		}
	}
	else if (d > s)
	{
		index = n;
		while (index > 0)
		{
			d[index - 1] = s[index - 1];
			index--;
		}
	}
	return (dest);
}

int	gnl_read_line(int fd, t_gnl_mem *mem)
{
	ssize_t	read_len;
	char	*tmp;

	if (mem->size + BUFFER_SIZE > mem->max_size)
	{
		mem->max_size += BUFFER_SIZE * ++mem->alloc_cnt;
		tmp = malloc(sizeof(char) * mem->max_size);
		if (tmp == NULL)
			return (-1);
		gnl_memmove(tmp, mem->data, mem->size);
		free(mem->data);
		mem->data = tmp;
	}
	read_len = read(fd, mem->data + mem->size, BUFFER_SIZE);
	if (read_len <= 0)
		return (read_len);
	mem->size += read_len;
	while (read_len > 0)
	{
		if (mem->data[mem->size - read_len--] == '\n')
			mem->line_cnt += 1;
	}
	return (1);
}
