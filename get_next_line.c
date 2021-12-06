/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:45:56 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/06 18:46:01 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char *str;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
	return (NULL);

	read(fd, str, BUFFER_SIZE);

/*
	char c;
	while (read(fd, &c, 1) && c != '\n')
		write(1, &c, 1);
*/
	return (str);
}