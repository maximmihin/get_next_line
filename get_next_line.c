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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str_buff;
	char 		*str_ret;
	int			i;
	int			have_str_buff;
	char *		find_end;
	char *		find_enter;
	size_t		len_buff_str;
	size_t		len_str;

	i = 1;
	have_str_buff = 0;
	find_end = 0;
	find_enter = 0;

	while(!find_enter && !find_end)
	{
		read(fd, buffer, BUFFER_SIZE);
		printf("buffer1 = %s\n", buffer);

		find_end = (char *)ft_memchr(buffer, '\0', BUFFER_SIZE);

		find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);

			if(!have_str_buff)
			{
				//make func str_init
				str_buff = (char *)malloc(BUFFER_SIZE + 1);
				if (!str_buff)
					return (NULL);
				printf("make str_buf\n");
				have_str_buff = 1;

				ft_memcpy(str_buff, buffer, BUFFER_SIZE);
				printf("str_buff1 = %s\n", str_buff);
			}
			else if (find_enter || find_end)
			{
				str_buff = ft_realloc(str_buff, BUFFER_SIZE * i + 1,
									  (BUFFER_SIZE * (i + 1)) + 1);

				ft_memcpy(&str_buff[BUFFER_SIZE * i], buffer, BUFFER_SIZE);
				printf("str_buff2 = %s\n", str_buff);
				i++;

			}
		printf("-----------------------------\n");
	}

	//don't forget '\0' in an and (1 line in file)
	len_str = (char *)ft_memchr(str_buff, '\n', BUFFER_SIZE * i) - str_buff;
	printf("len_str = %lu\n", len_str);

	str_ret = (char *) malloc(len_str + 1);

	ft_memcpy(str_ret, str_buff, len_str);
	printf("buffer3 = %s\n", buffer);

	//don't forget '\0' in an and (1 line in file)
	len_buff_str = (char *) ft_memchr(buffer, '\n', BUFFER_SIZE) - buffer;
	ft_memcpy(buffer, &buffer[len_buff_str + 1], BUFFER_SIZE - len_buff_str);
	buffer[BUFFER_SIZE - len_buff_str] = '\0';

	printf("buffer4 (fin) = %s\n", buffer);
	free(str_buff);



	//don't forget free all malloc!!!
/*
	char c;
	while (read(fd, &c, 1) && c != '\n')
		write(1, &c, 1);
*/
	return (str_ret);
}