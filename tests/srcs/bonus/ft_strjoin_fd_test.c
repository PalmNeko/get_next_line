/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:13:06 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 15:34:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"
#include <fcntl.h>
#include <stdlib.h>

TEST(ft_strjoin_fd, basic)
{
	int		fd;
	char	*joined;
	int		is_eof;

	is_eof = 0;
	fd = open("files/ft_strjoin_fd.txt", O_RDONLY);
	joined = ft_strjoin_fd("", fd, &is_eof, 1);
	ASSERT_TRUE(joined != NULL);
	ASSERT_FALSE(is_eof);
	EXPECT_STREQ(joined, "0");
	free(joined);
	joined = ft_strjoin_fd("abc", fd, &is_eof, 5);
	ASSERT_TRUE(joined != NULL);
	ASSERT_FALSE(is_eof);
	EXPECT_STREQ(joined, "abc12345");
	free(joined);
	joined = ft_strjoin_fd("abc", fd, &is_eof, 1024);
	ASSERT_TRUE(joined != NULL);
	ASSERT_FALSE(is_eof);
	EXPECT_STREQ(joined, "abc6789\n0123456789\n0123456789\n0123456789\n0123456789\n");
	free(joined);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(ft_strjoin_fd, check_eof)
{
	int		fd;
	char	*joined;
	int		is_eof;

	is_eof = 0;
	fd = open("files/ft_strjoin_fd.txt", O_RDONLY);
	joined = ft_strjoin_fd("abc", fd, &is_eof, 0);
	ASSERT_TRUE(joined != NULL);
	ASSERT_TRUE(is_eof);
	EXPECT_STREQ(joined, "abc");
	free(joined);
	is_eof = 0;
	joined = ft_strjoin_fd("", fd, &is_eof, 1024);
	ASSERT_TRUE(joined != NULL);
	ASSERT_FALSE(is_eof);
	free(joined);
	joined = ft_strjoin_fd("abc", fd, &is_eof, 1024);
	ASSERT_TRUE(joined != NULL);
	ASSERT_TRUE(is_eof);
	EXPECT_STREQ(joined, "abc");
	free(joined);
	ASSERT_TRUE(leak_check() == 0);
}
