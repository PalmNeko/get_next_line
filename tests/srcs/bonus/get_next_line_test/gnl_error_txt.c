/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_error_txt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:46:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 17:33:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include "tyctest.h"
#include <fcntl.h>
#include <unistd.h>

#define FILE_NAME "files/tester/read_error.txt"

TEST(get_next_line, read_error)
{
	int	fd;

	fd = open(FILE_NAME, O_RDONLY);
	ASSERT_EQ(gnl_test(fd, "aaaaaaaaaa\n"), 0);
	ASSERT_EQ(gnl_test(fd, "bbbbbbbbbb\n"), 0);
	while (gnl_test(fd, NULL) != 0)
		;
	ASSERT_EQ(gnl_test(fd, NULL), 0);
	close(fd);
	fd = open(FILE_NAME, O_RDONLY);
	ASSERT_EQ(gnl_test(fd, "aaaaaaaaaa\n"), 0);
	ASSERT_EQ(gnl_test(fd, "bbbbbbbbbb\n"), 0);
	ASSERT_EQ(gnl_test(fd, "cccccccccc\n"), 0);
	ASSERT_EQ(gnl_test(fd, "dddddddddd\n"), 0);
	ASSERT_EQ(gnl_test(fd, NULL), 0);
	ASSERT_EQ(leak_check(), 0);
	close(fd);
}
