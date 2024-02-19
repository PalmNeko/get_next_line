/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:03:50 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 16:44:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "get_next_line_bonus.h"

t_pl	*new_t_pl(void);
t_pl	*create_test_pl(void);
int		leak_check(void);
int		_gnl_test(int fd, char *to_be);
int		gnl_test(int fd, char *to_be);

#endif