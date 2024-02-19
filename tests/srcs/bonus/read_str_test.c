/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:47:22 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 15:20:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tyctest.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

TEST(read_str, basic)
{
	int		fd;
	char	*str;

	fd = open("files/read_str.txt", O_RDONLY);
	str = read_str(fd, 10);
	ASSERT_TRUE(str != NULL);
	EXPECT_STREQ(str, "0123456789");
	free(str);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
	str = read_str(fd, 10);
	ASSERT_TRUE(str != NULL);
	EXPECT_STREQ(str, "\n");
	free(str);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
	str = read_str(fd, 10);
	ASSERT_TRUE(str != NULL);
	EXPECT_STREQ(str, "");
	free(str);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
	str = read_str(-1, 10);
	EXPECT_TRUE(str == NULL);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
	close(fd);
}
