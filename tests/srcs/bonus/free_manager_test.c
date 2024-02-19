/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:56:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 14:55:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"
#include <stdlib.h>
#include <errno.h>

TEST(free_manager, free_string)
{
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * 1);
	if (s1 == NULL)
		exit(errno);
	free_manager(&s1, NULL);
	EXPECT_TRUE(s1 == NULL);
}

TEST(free_manager, free_t_pl_basic)
{
	t_pl	*test;

	test = new_t_pl();
	if (test == NULL)
		exit(1);
	free_manager(NULL, &test);
	EXPECT_TRUE(test == NULL);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(free_manager, free_t_pl_more_left)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(free_manager, free_t_pl_more_center)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	test = test->next;
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(free_manager, free_t_pl_more_right)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	test = test->next;
	test = test->next;
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(leak_check() == 0);
}
