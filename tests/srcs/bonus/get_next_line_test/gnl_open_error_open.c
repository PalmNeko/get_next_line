/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_open_error_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:20:42 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/04 13:41:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include "tyctest.h"
#include <fcntl.h>
#include <unistd.h>

TEST(get_next_line, open_error_open)
{
	int			fd;
	int			fd2;
	const char	*name = "files/tester/read_error.txt";
	const char	*other = "files/tester/lines_around_10.txt";

	fd = open(name, O_RDONLY);
	fd2 = open(other, O_RDONLY);
	ASSERT_EQ(gnl_test(fd, "aaaaaaaaaa\n"), 0);
	ASSERT_EQ(gnl_test(fd2, "0123456789\n"), 0);
	ASSERT_EQ(gnl_test(fd, "bbbbbbbbbb\n"), 0);
	ASSERT_EQ(gnl_test(fd2, "012345678\n"), 0);
	while (gnl_test(fd, NULL) != 0)
		;
	ASSERT_EQ(gnl_test(fd, NULL), 0);
	close(fd);
	ASSERT_EQ(gnl_test(fd2, "90123456789\n"), 0);
	fd = open(name, O_RDONLY);
	ASSERT_EQ(gnl_test(fd, "aaaaaaaaaa\n"), 0);
	ASSERT_EQ(gnl_test(fd2, "0123456789\n"), 0);
	ASSERT_EQ(gnl_test(fd, "bbbbbbbbbb\n"), 0);
	ASSERT_EQ(gnl_test(fd, "cccccccccc\n"), 0);
	ASSERT_EQ(gnl_test(fd2, "xxxx\n"), 0);
	ASSERT_EQ(gnl_test(fd2, NULL), 0);
	ASSERT_EQ(gnl_test(fd, "dddddddddd\n"), 0);
	ASSERT_EQ(gnl_test(fd, NULL), 0);
	close(fd);
}
