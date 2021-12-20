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
