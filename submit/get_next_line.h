/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:20:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 19:37:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_gnl_node
{
	int		fd;
	char	*carry_up;
}	t_gnl_node;

typedef void	(*t_free)(void *);

char	*get_next_line(int fd);
char	*get_next_line2(int fd, char **carry_up);

void	*gnl_memmove(void *dest, const void *src, size_t n);
void	gnl_lstadd_back(t_list **lst, t_list *new);
void	gnl_lstclear(t_list **lst, void (*del)(void *));
void	gnl_lstdelone(t_list *lst, void (*del)(void *));
t_list	*gnl_lstnew(void *content);

#endif
