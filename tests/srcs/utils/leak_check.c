/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:21:17 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 16:13:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		leak_check(void)
{
	int	result;

	result = system("leaks -q bonus >> leaks.log");
	if (result != 0)
	{
		fprintf(stderr, "\033[31mLEAK ERROR\033[m\n");
		exit(1);
	}
	return (result);
}
