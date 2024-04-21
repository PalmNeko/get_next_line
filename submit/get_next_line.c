/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:49:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/04/21 15:07:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

// int	main(int argc, char *argv[])
// {
// 	char	*line;
// 	int		fd;

// 	fd = 0;
// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], 0);
// 		if (fd < 0)
// 			return (1);
// 	}
// 	line = get_next_line_fd(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line_fd(fd);
// 	}
// 	printf("%d\n", errno);
// 	fflush(stdout);
// 	return (0);
// }
