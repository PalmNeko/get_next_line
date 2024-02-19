/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:42:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 16:44:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include <string.h>
#include <stdlib.h>

int	gnl_test(int fd, char *to_be)
{
	char	*line;
	int		comp_result;

	line = get_next_line(fd);
	if (line == NULL && to_be == NULL)
		comp_result = 0;
	else if (line == NULL || to_be == NULL)
		comp_result = 2;
	else
		comp_result = strcmp(line, to_be);
	free(line);
	return (comp_result);
}
