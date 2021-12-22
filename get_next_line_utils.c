/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:46:26 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/06 18:46:28 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	int				i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (n)
	{
		dest[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n)
	{
		if (*str == (unsigned char)c)
			return (str);
		else
		{
			str++;
			n--;
		}
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (n > i)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*ft_realloc(char *buff, int oldlen, int newlen)
{
	char	*box;

	if (newlen == 0)
	{
		free(buff);
		return (NULL);
	}
	else if (!buff)
	{
		buff = (char *) malloc(newlen);
		return (buff);
	}
	else if (newlen <= oldlen)
		return (buff);
	else
	{
		box = (char *) malloc(newlen);
		if (box)
		{
			ft_bzero(box, newlen);
			ft_memcpy(box, buff, oldlen);
			free(buff);
		}
		return (box);
	}
}



size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	else if (len >= slen)
		len = slen - start;
	arr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (len && s[start] && start < slen)
	{
		arr[i] = s[start];
		i++;
		start++;
		len--;
	}
	arr[i] = 0;
	return (arr);
}

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s != '\0')
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}