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

char	*buffer_preproc(char *buffer)
{
	char		*find_enter;
	char 		*str_ret;
	int 		len;

	find_enter = ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (find_enter)
	{
		len = find_enter - &buffer[0];
		ft_memcpy(buffer, find_enter, BUFFER_SIZE - len);
	}
	//
	find_enter = ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (find_enter)
	{
		len = find_enter - &buffer[0];
		str_ret = ft_substr(buffer, 0, len);
	}
	else
	{
		str_ret = (char *) malloc(BUFFER_SIZE + 1);
		if (!str_ret)
			return (NULL);
		str_ret[BUFFER_SIZE] = '\0';
	}
	return (str_ret);
}

char 	*ft_read(int fd, char *buffer, char **str_buff)
{
	char 	*find_enter;
	char 	*str_ret;
	int		buff_read;

	buff_read = 1;
	while(!ft_memchr(buffer, '\n', BUFFER_SIZE) && buff_read > 0)
	{
		printf("BP 1\n");
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if (buff_read < 0)
		{
			free(str_buff);
			return(NULL);
		}
		if (buff_read == 0)
			return (str_ret);
		str_ret = ft_strjoin_gnl(str_buff, buffer);
		printf("str_ret = %s\n", str_ret);
		printf("BP 2\n");
	}
	find_enter = ft_strchr(str_buff, '\n');
	*(find_enter + 1) = '\0';

	return (str_buff);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str_buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

	str_buff = buffer_preproc(buffer);
	if (!str_buff)
		return (NULL);

	if (*str_buff == '\0')
		str_buff = ft_read(fd, buffer, str_buff);

	return (str_buff);



}