/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gradagas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:46:54 by gradagas          #+#    #+#             */
/*   Updated: 2021/12/06 18:46:56 by gradagas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

//del
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_realloc(char *buff, int oldlen, int newlen);


size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
