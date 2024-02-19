/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_test_pl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 14:15:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include <stdlib.h>

t_pl	*create_test_pl(void)
{
	t_pl	*left;
	t_pl	*right;
	t_pl	*center;

	left = new_t_pl();
	if (left == NULL)
		exit(1);
	right = new_t_pl();
	if (right == NULL)
		exit(1);
	center = new_t_pl();
	if (center == NULL)
		exit(1);
	left->next = center;
	center->previous = left;
	center->next = right;
	right->previous = center;
	return (left);
}
