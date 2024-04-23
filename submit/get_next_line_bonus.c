/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:49:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/04/23 17:02:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_gnl_cut(t_gnl_mem *mem);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		read_line(int fd, t_gnl_mem *mem);

char	*get_next_line(int fd)
{
	static t_gnl_mem_lst	*mem;
	t_gnl_mem_lst			*used_mem;
	char					*line;

	used_mem = gnl_get_mem(&mem, fd);
	if (used_mem == NULL)
	{
		used_mem = gnl_new_mem(fd);
		if (used_mem == NULL)
			return (NULL);
		gnl_add_mem(&mem, used_mem);
	}
	line = get_next_line_mem(used_mem->mem, fd);
	if (line == NULL)
		gnl_del_mem(&used_mem);
	mem = used_mem;
	return (line);
}

char	*get_next_line_mem(t_gnl_mem *mem, int fd)
{
	ssize_t				result;
	char				*line;

	result = 0;
	if (mem->line_cnt == 0)
		result = 1;
	while (result > 0 && mem->line_cnt == 0)
		result = read_line(fd, mem);
	if (result == -1)
		return (NULL);
	line = ft_gnl_cut(mem);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_gnl_cut(t_gnl_mem *mem)
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
	ft_memmove(line, mem->data, cp_len);
	line[cp_len] = '\0';
	ft_memmove(mem->data, line_ptr + 1, (mem->size - cp_len));
	mem->size = (mem->size - cp_len);
	mem->line_cnt -= 1;
	return (line);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
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

int	read_line(int fd, t_gnl_mem *mem)
{
	ssize_t	read_len;
	char	*tmp;

	if (mem->size + BUFFER_SIZE > mem->max_size)
	{
		mem->max_size += BUFFER_SIZE * ++mem->alloc_cnt;
		tmp = malloc(sizeof(char) * mem->max_size);
		if (tmp == NULL)
			return (-1);
		ft_memmove(tmp, mem->data, mem->size);
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
