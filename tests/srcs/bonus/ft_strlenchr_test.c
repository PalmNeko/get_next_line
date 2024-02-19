/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenchr_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:49:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 17:34:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "get_next_line_bonus.h"

TEST(ft_strlenchr, basic)
{
	EXPECT_EQ(ft_strlenchr("", 'a'), 0);
	EXPECT_EQ(ft_strlenchr("123", 'a'), 3);
	EXPECT_EQ(ft_strlenchr("123\n123\n", '\n'), 3);
	EXPECT_EQ(ft_strlenchr("\n123\n123\n", '\n'), 0);
	EXPECT_EQ(ft_strlenchr("\n", '\n'), 0);
	EXPECT_EQ(ft_strlenchr("\n", '1'), 1);
}