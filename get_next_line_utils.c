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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (arr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = 0;
	while (*dst && d_len < dstsize)
	{
		dst++;
		d_len++;
	}
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	dstsize -= d_len + 1;
	while (dstsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (d_len + s_len);
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	else
	{
		i = (int) len;
		while (i)
		{
			*(char *)(dst + i - 1) = *(char *)(src + i - 1);
			i--;
		}
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

char	*ft_realloc(char *buff, int oldlen, int newlen)
{
	printf("oldlen = %d\n", oldlen);
	printf("newlen = %d\n", newlen);
	char *box;
	int counter;

	counter = 0;
	box = (char*) malloc(sizeof(char) * newlen);
	if (!box)
		return (NULL);
	while(oldlen != 0)
	{
		box[counter] = buff[counter];
		counter++;
		oldlen--;
	}
	free(buff);
	return (box);
}
