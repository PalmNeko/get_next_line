/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gnl_singleline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:16:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 15:18:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"
#include <fcntl.h>
#include <unistd.h>

#define FILE_NAME "files/gnl/singleline.txt"

TEST(_get_next_line, singleline)
{
	int		fd;

	fd = open(FILE_NAME, O_RDONLY);
	_gnl_test(-1, NULL); // 初期化
	ASSERT_EQ(_gnl_test(fd, "123403923"), 0);
	ASSERT_EQ(_gnl_test(fd, NULL), 0);
	ASSERT_TRUE(leak_check() == 0);
	_gnl_test(-1, NULL); // 初期化
	close(fd);
}
