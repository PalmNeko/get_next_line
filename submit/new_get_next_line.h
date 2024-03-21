/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:20:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/21 19:20:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_GET_NEXT_LINE_H
# define NEW_GET_NEXT_LINE_H

# include <stddef.h>

# define BUFFER_SIZE 2

typedef struct {
	char	*data;
	size_t	size;
	size_t	max_size;
	size_t	alloc_cnt;
	size_t	line_cnt;
}	t_gnl_mem;

char *get_next_line_fd(int fd);

#endif
