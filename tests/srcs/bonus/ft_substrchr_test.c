/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrchr_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:57:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 17:14:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include <stdlib.h>

TEST(ft_substrchr, basic)
{
	char	*sub;

	sub = ft_substrchr("0123456789", '0');
	ASSERT_TRUE(sub != NULL);
	EXPECT_STREQ(sub, "0");
	free(sub);
	sub = ft_substrchr("0123456789", '9');
	ASSERT_TRUE(sub != NULL);
	EXPECT_STREQ(sub, "0123456789");
	free(sub);
	sub = ft_substrchr("0123456789", '3');
	ASSERT_TRUE(sub != NULL);
	EXPECT_STREQ(sub, "0123");
	free(sub);
	sub = ft_substrchr("0123456789", 'a');
	ASSERT_TRUE(sub != NULL);
	EXPECT_STREQ(sub, "0123456789");
	free(sub);
	sub = ft_substrchr("\n" + 1, 'a');
	ASSERT_TRUE(sub != NULL);
	EXPECT_STREQ(sub, "");
	free(sub);
}
