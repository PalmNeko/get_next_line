/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:51:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 19:37:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>
#include <stdlib.h>

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				index;

	d = dest;
	s = src;
	if (d < s)
	{
		index = 0;
		while (index < n)
		{
			d[index] = s[index];
			index++;
		}
	}
	else if (d > s)
	{
		index = n;
		while (index > 0)
		{
			d[index - 1] = s[index - 1];
			index--;
		}
	}
	return (dest);
}

void	gnl_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_list = *lst;
	while (last_list->next != NULL)
		last_list = last_list->next;
	new->next = last_list->next;
	new->prev = last_list;
	last_list->next = new;
	return ;
}

void	gnl_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*itr;
	t_list	*free_lst;
	t_list	*start;

	if (lst == NULL || *lst == NULL)
		return ;
	itr = (*lst);
	if (itr->prev != NULL)
	{
		itr = itr->prev;
		itr->next->prev = NULL;
	}
	while (itr->prev != NULL)
		itr = itr->prev;
	start = itr;
	itr = itr->next;
	while (itr != NULL && itr != start)
	{
		free_lst = itr;
		itr = itr->next;
		gnl_lstdelone(free_lst, del);
	}
	gnl_lstdelone(start, del);
	*lst = NULL;
	return ;
}

void	gnl_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (lst->prev != NULL)
		lst->prev->next = lst->next;
	if (lst->next != NULL)
		lst->next->prev = lst->prev;
	del(lst->content);
	free(lst);
}

t_list	*gnl_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	*new = (t_list){
		.content = content,
		.next = NULL,
		.prev = NULL
	};
	return (new);
}
