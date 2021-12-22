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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*arr;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof (*s1) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		arr[i] = *s2++;
		i++;
	}
	arr[i] = 0;
	free (s1);
	return (arr);
}

char	*buffer_preproc(char *buffer)
{
	char		*find_enter;
	char		*str_buff;
	int			len;

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
		len = find_enter - &buffer[0];
		if (find_enter == &buffer[0])
			return (ft_substr("\n", 0, 1));
		str_buff = ft_substr(buffer, 0, len + 1);
	}
	else
		str_buff = ft_substr("\0", 0, 1);
	return (str_buff);
}

char	*str_ret_preproc(char *buffer)
{
	char		*str_ret;

	if (*buffer)
		str_ret = ft_substr(buffer, 0, ft_strlen(buffer));
	else
		str_ret = ft_substr("\0", 0, 1);
	return (str_ret);
}

char	*ft_read(int fd, char *buffer)
{
	char	*find_enter;
	char	*str_ret;
	int		buff_read;

	buff_read = 1;
	str_ret = str_ret_preproc(buffer);
	while (!ft_strchr(buffer, '\n') && buff_read > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		buff_read = read(fd, buffer, BUFFER_SIZE);
		if (buff_read < 0 || (buff_read == 0 && str_ret[0] == '\0'))
		{
			free(str_ret);
			return (NULL);
		}
		if (buff_read == 0)
			return (str_ret);
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
