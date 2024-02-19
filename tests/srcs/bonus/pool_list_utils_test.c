/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_list_utils_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:02:00 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 14:56:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"

TEST(pool_list_utils, basic_new)
{
	t_pl	*tmp;

	tmp = pool_list_utils(NULL, NULL, 3, pl_new);
	ASSERT_TRUE(tmp != NULL);
	EXPECT_EQ(tmp->fd, 3);
	EXPECT_TRUE(tmp->next == NULL);
	EXPECT_TRUE(tmp->previous == NULL);
	EXPECT_TRUE(tmp->str == NULL);
	free_manager(NULL, &tmp);
	ASSERT_TRUE(tmp == NULL);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(pool_list_utils, basic_add_front)
{
	t_pl	*root;
	t_pl	*tmp;

	root = create_test_pl();
	ASSERT_TRUE(root != NULL);
	tmp = pool_list_utils(NULL, NULL, 3, pl_new);
	ASSERT_TRUE(tmp != NULL);
	root = root->next->next;
	pool_list_utils(&root, &tmp, 0, pl_add_front);
	ASSERT_TRUE(root == tmp);
	pool_list_utils(&root, NULL, 0, pl_clear);
	ASSERT_TRUE(root == NULL);
	ASSERT_TRUE(leak_check() == 0);
}

TEST(pool_list_utils, basic_pl_clear)
{
	t_pl	*root;

	root = create_test_pl();
	ASSERT_TRUE(root != NULL);
	pool_list_utils(&root, NULL, 0, pl_clear);
	ASSERT_TRUE(root == NULL);
	ASSERT_TRUE(leak_check() == 0);
}
