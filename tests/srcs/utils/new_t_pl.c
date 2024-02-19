/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:05:20 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 14:16:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <string.h>

t_pl	*new_t_pl(void)
{
	t_pl	*tmp;

	tmp = (t_pl *)malloc(sizeof(t_pl) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp->fd = 0;
	tmp->next = NULL;
	tmp->previous = NULL;
	tmp->str = strdup("123");
	return (tmp);
}
