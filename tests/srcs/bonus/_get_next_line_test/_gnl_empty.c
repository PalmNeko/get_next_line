/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gnl_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:31 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 14:15:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"
#include <fcntl.h>

#define FILE_NAME "files/gnl/empty.txt"

TEST(_get_next_line, empty)
{
	char	*pool;
	char	*leftovers;
	char	*line;
	int		fd;

	leftovers = NULL;
	fd = open(FILE_NAME, O_RDONLY);
	pool = ft_substrchr("", 'a');
	ASSERT_TRUE(pool != NULL);
	line = _get_next_line(&pool, fd, &leftovers);
	ASSERT_TRUE(line == NULL);
	ASSERT_TRUE(pool != NULL);
	ASSERT_TRUE(leftovers == NULL);
	free(pool);
	ASSERT_TRUE(leak_check() == 0);
}
