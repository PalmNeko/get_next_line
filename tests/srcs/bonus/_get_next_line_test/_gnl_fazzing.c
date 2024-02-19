/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gnl_fazzing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:57:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 14:16:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"
#include <fcntl.h>

#define FILE_NAME "files/gnl/fazzing.txt"

TEST(_get_next_line, fazzing_basic)
{
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	_gnl_test(-1, NULL); // 初期化
	ASSERT_EQ(_gnl_test(fd, "\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "0\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "3210\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "0\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "0123\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "\n"), 0);
	ASSERT_EQ(_gnl_test(fd, "\n"), 0);
	ASSERT_EQ(_gnl_test(fd, NULL), 0);
	ASSERT_TRUE(leak_check() == 0);
	_gnl_test(-1, NULL); // 初期化
}