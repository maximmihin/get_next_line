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

char 	*buffer_preproc(char *buffer, char **find_enter, int *len_str)
{
	char 		*str;

	if (buffer[BUFFER_SIZE] == '!')
		return	(NULL);

	//1 and 2
	*find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (!*buffer || *find_enter == &buffer[BUFFER_SIZE - 1])
	{
//		printf("CASE 1\n");
		ft_bzero(buffer, BUFFER_SIZE + 1);
		*find_enter = NULL;
		str = (char *) malloc(BUFFER_SIZE + 1);
		return (str);
	}

	//3
	if (*find_enter)
	{
//		printf("CASE 3\n");
		*len_str = &buffer[BUFFER_SIZE] - *find_enter - 1;
		str = (char *) malloc(*len_str + BUFFER_SIZE + 1);
		ft_bzero(str, *len_str + BUFFER_SIZE + 1);
		ft_memcpy(str, *find_enter + 1, *len_str);

		*find_enter = (NULL);
	}

	//4
	*find_enter = (char *)ft_memchr(str, '\n', BUFFER_SIZE);
	if (*find_enter)
	{
//		printf("CASE 4\n");
		*find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
		**find_enter = 's';
	}
	else
		ft_bzero(buffer, BUFFER_SIZE + 1);

	return (str);
}



char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*find_enter;
	char		*str_buff;
	int 		sbf; //start buffer len;
	int			i;

//	printf("*** Start gnl ***\n");
	sbf = 0;
	i = 0;

//	printf("buffer cont 1 = %s\n", buffer);
	//printf("str_buff cont b = %s\n", str_buff);
	str_buff = buffer_preproc(buffer, &find_enter, &sbf);
	if (!str_buff)
		return (NULL);
//	printf("buffer cont a = %s\n", buffer);
//	printf("str_buff cont a = %s\n", str_buff);
//	printf("BP 1\n");

	while(!buffer[BUFFER_SIZE] && !find_enter)
	{
		if(!read(fd, buffer, BUFFER_SIZE))
		{
//			printf("Find end!\n");
			return (NULL);
		}

//		find (&find_enter, buffer, BUFFER_SIZE);
		find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);



//		printf("* BP 1\n");
//		printf("buffer = %s", buffer);
		ft_memcpy(&str_buff[BUFFER_SIZE * i + sbf], buffer, BUFFER_SIZE);
//		printf("* BP 2\n");
		//to del
		//str_buff[BUFFER_SIZE * i + 1] = '\0';
//		printf("str_buff = %s\n", str_buff);

		i++;
		//here bug in len. First time oldlen != B_S * i + 1 + sbf)
		if (!buffer[BUFFER_SIZE] && !find_enter)
			str_buff = ft_realloc (str_buff, BUFFER_SIZE * i + 1 + sbf,
							  BUFFER_SIZE * (i + 1) + 1 + sbf);
//		printf("str_buff (ar) = %s\n", str_buff);
//		printf("BP 2\n");
//		printf("find_enter = %p\n", find_enter);

		//i++;
	}

	find_enter = ft_memchr(str_buff, '\n', BUFFER_SIZE * (i + 1) + sbf);
//	printf("find_enter2 = %p\n", find_enter);
	*find_enter = '\0';


/*
	printf("BP 3\n");
	printf("str_buff = %s\n", str_buff);
	printf("buffer cont 2 = %s\n", buffer);
*/


	return (str_buff);
}
