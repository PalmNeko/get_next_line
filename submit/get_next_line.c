/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:49:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/04/21 15:45:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static t_gnl_mem	mem;
	char				*line;

	line = get_next_line_mem(&mem, fd);
	if (line == NULL)
	{
		free(mem.data);
		mem = (t_gnl_mem){0};
		return (NULL);
	}
	return (line);
}
