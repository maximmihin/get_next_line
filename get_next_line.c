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
	char 		*str_buff;
	int 		len;
	int 		len2;

	find_enter = ft_strchr(buffer, '\n');
	if (find_enter)
	{
		len = find_enter - &buffer[0];
		ft_memcpy(buffer, find_enter + 1, BUFFER_SIZE - len);
		buffer[BUFFER_SIZE - len] = '\0';
	}
	else
		ft_bzero(buffer, BUFFER_SIZE);
	find_enter = ft_strchr(buffer, '\n');
	if (find_enter)
	{
		len2 = find_enter - &buffer[0];
		if (find_enter == &buffer[0])
			return(ft_substr("\n", 0, 1));
		str_buff = ft_substr(buffer, 0, len2 + 1);
	}
	else
		str_buff = ft_substr("\0", 0, 1);
	return (str_buff);
}

char 	*ft_read(int fd, char *buffer)
{
	char 	*find_enter;
	char 	*str_ret;
	int		buff_read;

	buff_read = 1;
	if (*buffer)
	{
		str_ret = ft_substr(buffer, 0, ft_strlen(buffer));
		buffer[0] = '\0';
	}
	else
		str_ret = ft_substr("\0", 0, 1);
	while(!ft_strchr(buffer, '\n') && buff_read > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if (buff_read < 0)
		{
			free(str_ret);
			return(NULL);
		}
		if (buff_read == 0)
		{
			if (str_ret[0] == '\0')
			{
				free(str_ret);
				return (NULL);
			}
			return (str_ret);
		}
		str_ret = ft_strjoin_gnl(str_ret, buffer);
	}
	find_enter = ft_strchr(str_ret, '\n');
	*(find_enter + 1) = '\0';
	return (str_ret);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str_buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str_buff = buffer_preproc(buffer);
	if (*str_buff || !str_buff)
		return (str_buff);
	free(str_buff);
	str_buff = ft_read(fd, buffer);
	return (str_buff);
}