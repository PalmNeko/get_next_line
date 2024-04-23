/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:55:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/04/21 17:22:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_gnl_mem {
	char	*data;
	size_t	size;
	size_t	max_size;
	size_t	alloc_cnt;
	size_t	line_cnt;
}	t_gnl_mem;

typedef struct s_gnl_mem_lst	t_gnl_mem_lst;
struct s_gnl_mem_lst {
	int				fd;
	t_gnl_mem		*mem;
	t_gnl_mem_lst	*next;
	t_gnl_mem_lst	*prev;
};

char			*get_next_line(int fd);
char			*get_next_line_mem(t_gnl_mem *mem, int fd);

t_gnl_mem_lst	*gnl_get_mem(t_gnl_mem_lst **lst, int fd);
void			gnl_del_mem(t_gnl_mem_lst **lst);
void			gnl_add_mem(t_gnl_mem_lst **root, t_gnl_mem_lst *new);
t_gnl_mem_lst	*gnl_new_mem(int fd);
void			gnl_clear_all_mem(t_gnl_mem_lst **lst);

#endif
