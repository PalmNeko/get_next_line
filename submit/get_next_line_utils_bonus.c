/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:55:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/04/23 17:02:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

t_gnl_mem_lst	*gnl_get_mem(t_gnl_mem_lst **lst, int fd)
{
	t_gnl_mem_lst	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
		{
			*lst = tmp;
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
		{
			*lst = tmp;
			return (tmp);
		}
		tmp = tmp->prev;
	}
	return (NULL);
}

void	gnl_del_mem(t_gnl_mem_lst **lst)
{
	t_gnl_mem_lst	*tmp;
	int				fd;

	tmp = *lst;
	fd = tmp->fd;
	if (tmp->prev != NULL)
		*lst = tmp->prev;
	else if (tmp->next != NULL)
		*lst = tmp->next;
	else
		*lst = NULL;
	if (tmp == NULL)
		return ;
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	free(tmp->mem->data);
	free(tmp->mem);
	free(tmp);
	return ;
}

void	gnl_add_mem(t_gnl_mem_lst **root, t_gnl_mem_lst *new)
{
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	if ((*root)->prev != NULL)
	{
		(*root)->prev->next = new;
		new->prev = (*root)->prev;
	}
	(*root)->prev = new;
	new->next = *root;
	*root = new;
}

t_gnl_mem_lst	*gnl_new_mem(int fd)
{
	t_gnl_mem_lst	*new_lst;

	new_lst = (t_gnl_mem_lst *)malloc(sizeof(t_gnl_mem_lst));
	if (new_lst == NULL)
		return (NULL);
	new_lst->mem = (t_gnl_mem *)malloc(sizeof(t_gnl_mem));
	if (new_lst->mem == NULL)
		return (free(new_lst), NULL);
	*new_lst->mem = (t_gnl_mem){
		.alloc_cnt = 0, .data = NULL, .line_cnt = 0, .max_size = 0, .size = 0};
	new_lst->fd = fd;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	gnl_clear_all_mem(t_gnl_mem_lst **lst)
{
	t_gnl_mem_lst	*next;

	while (*lst != NULL && (*lst)->prev != NULL)
		*lst = (*lst)->prev;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		free((*lst)->mem->data);
		free((*lst)->mem);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
