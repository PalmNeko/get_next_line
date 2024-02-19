/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gnl_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 16:44:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	_gnl_test(int fd, char *to_be)
{
	static char	*pool;
	char		*line;
	char		*leftovers;
	int			comp_result;

	if (pool == NULL)
		pool = ft_substrchr("", 'a');
	if (pool == NULL)
		return (-1);
	else if (fd < 0)
	{
		free(pool);
		pool = NULL;
		return (0);
	}
	line = _get_next_line(&pool, fd, &leftovers);
	free(pool);
	if (line != NULL)
		pool = leftovers;
	else
		pool = NULL;
	if (line == NULL && to_be == NULL)
		comp_result = 0;
	else if (line == NULL || to_be == NULL)
		comp_result = 2;
	else
		comp_result = strcmp(line, to_be);
	free(line);
	return (comp_result);
}
