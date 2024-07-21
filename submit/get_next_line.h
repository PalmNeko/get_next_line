/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:20:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/21 12:37:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

char	*get_next_line(int fd);
char	*gnl_get_next_line_mem(t_gnl_mem *mem, int fd);

#endif
