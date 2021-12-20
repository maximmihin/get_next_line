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

char	*buffer_preproc_cases(char *buffer, int *len_str, char *find_enter,
								char *str_buff)
{
	char		*find_end;
	int			len;

	find_end = ft_memchr(buffer, '\0', BUFFER_SIZE);
	if (find_end)
		*len_str = find_end - &buffer[0] - 1;
	else
		*len_str = &buffer[BUFFER_SIZE] - find_enter - 1;
	str_buff = (char *) malloc(*len_str + BUFFER_SIZE + 1);
	if (!str_buff)
		return (NULL);
	ft_bzero(str_buff, *len_str + BUFFER_SIZE + 1);
	ft_memcpy(str_buff, find_enter + 1, *len_str);
	find_enter = (char *)ft_memchr(str_buff, '\n', BUFFER_SIZE);
	if (find_enter)
	{
		find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
		len = find_enter - buffer + 1;
		ft_memcpy(buffer, buffer + len, BUFFER_SIZE - len);
		buffer[BUFFER_SIZE - len] = '\0';
		buffer[BUFFER_SIZE] = '?';
	}
	else
		ft_bzero(buffer, BUFFER_SIZE + 1);
	return (str_buff);
}

char	*buffer_preproc(char *buffer, int *len_str)
{
	char		*str_buff;
	char		*find_enter;

	find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (!*buffer || find_enter == &buffer[BUFFER_SIZE - 1])
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		find_enter = NULL;
		str_buff = (char *) malloc(BUFFER_SIZE + 1);
		if (!str_buff)
			return (NULL);
		ft_bzero(str_buff, BUFFER_SIZE);
		return (str_buff);
	}
	str_buff = find_enter;
	str_buff = buffer_preproc_cases(buffer, len_str, find_enter, str_buff);
	return (str_buff);
}

char	*str_return(char *str_buff, int sbf, int i)
{
	char		*find_enter;

	find_enter = ft_memchr(str_buff, '\n', BUFFER_SIZE * i + sbf + 1);
	*(find_enter + 1) = '\0';
	return (str_buff);
}

char	*proc(char *buffer, char *str_buff, int sbf, int fd)
{
	int			r;
	int			i;

	i = 0;
	while (!buffer[BUFFER_SIZE])
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r > 0)
		{
			ft_memcpy(&str_buff[BUFFER_SIZE * i++ + sbf], buffer, r);
			if (ft_memchr(buffer, '\n', BUFFER_SIZE))
				return (str_return(str_buff, sbf, i));
			str_buff = ft_realloc(str_buff, BUFFER_SIZE * i + sbf + 1,
					BUFFER_SIZE * (i + 1) + sbf + 1);
			ft_bzero(buffer, BUFFER_SIZE);
		}
		else
		{
			if (r == 0 && *str_buff)
				return (str_buff);
			free(str_buff);
			return (NULL);
		}
	}
	return (str_buff);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str_buff;
	int			sbf;
	char		*find_enter;
	int			len;

	sbf = 0;
	str_buff = buffer_preproc(buffer, &sbf);
	if (!str_buff)
		return (NULL);
	if (buffer[BUFFER_SIZE] != '?')
	{
		str_buff = proc(buffer, str_buff, sbf, fd);
		return (str_buff);
	}
	find_enter = ft_memchr(buffer, '\n', BUFFER_SIZE);
	len = find_enter - &buffer[0] + 1;
	ft_memcpy(str_buff, buffer, len);
	str_buff[len] = '\0';
	return (str_buff);
}
