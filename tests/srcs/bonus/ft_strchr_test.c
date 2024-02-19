/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:18:56 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 13:56:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"

TEST(ft_strchr_test, basic)
{
	EXPECT_STREQ(ft_strchr("0123456", '3'), "3456");
	EXPECT_STREQ(ft_strchr("0123456", '6'), "6");
	EXPECT_STREQ(ft_strchr("0123456", '\0'), "");
	EXPECT_STREQ(ft_strchr("0123456", '0'), "0123456");
	EXPECT_TRUE(ft_strchr("0123456", 'a') == NULL);
	EXPECT_STREQ(ft_strchr("", '\0'), "");
	EXPECT_TRUE(ft_strchr("", 'a') == NULL);
}
