/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_pl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:25:28 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 16:28:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include "test_utils_bonus.h"

TEST(get_target_pl, basic)
{
	t_pl	*root;
	t_pl	*target;

	root = NULL;
	target = get_target_pl(&root, 3);
	ASSERT_TRUE(target != NULL);
	ASSERT_STREQ(target->str, "");
	ASSERT_TRUE(target == root);
	ASSERT_TRUE(target->next == NULL);
	ASSERT_TRUE(target->previous == NULL);
	ASSERT_TRUE(target->fd == 3);
	free(target->str);
	target->str = ft_substrchr("123", '\0');
	target = get_target_pl(&root, 4);
	ASSERT_STREQ(target->str, "");
	ASSERT_TRUE(target->next != NULL);
	ASSERT_TRUE(target->previous == NULL);
	ASSERT_TRUE(target->fd == 4);
	target = get_target_pl(&root, 3);
	ASSERT_TRUE(target != NULL);
	ASSERT_STREQ(target->str, "123");
	ASSERT_TRUE(target == root);
	ASSERT_TRUE(target->next == NULL);
	ASSERT_TRUE(target->previous != NULL);
	ASSERT_TRUE(target->fd == 3);
	free_manager(NULL, &target);
	ASSERT_STREQ(target->str, "");
	ASSERT_TRUE(target->next == NULL);
	ASSERT_TRUE(target->previous == NULL);
	ASSERT_TRUE(target->fd == 4);
	free_manager(NULL, &target);
	ASSERT_TRUE(target == NULL);
	ASSERT_TRUE(leak_check() == 0);
}
