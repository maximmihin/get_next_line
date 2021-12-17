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

//	printf("c = %c\n", buffer[BUFFER_SIZE]);
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
		if (!str)
			return (NULL);
		return (str);
	}

	//3
//	printf("CASE 3\n");
	*len_str = &buffer[BUFFER_SIZE] - *find_enter - 1;
//	printf("*len_str = %d\n", *len_str + BUFFER_SIZE + 1);
	str = (char *) malloc(*len_str + BUFFER_SIZE + 1);
	if (!str)
	{
//		printf("return NULL 1\n");
		return (NULL);
	}
	ft_bzero(str, *len_str + BUFFER_SIZE + 1);
	ft_memcpy(str, *find_enter + 1, *len_str);

	*find_enter = (NULL);

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

//	printf("return str (preproc)\n");
	return (str);
}



char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*find_enter;
	char		*str_buff;
	int 		sbf; //start buffer len;
	int			i;
	int			r;

//	printf("\n*** Start gnl ***\n");
	sbf = 0;
	i = 0;

//	printf("buffer cont 1 = %s\n", buffer);
	//printf("str_buff cont b = %s\n", str_buff);
//	printf("BP 0.1\n");
//	printf("buffer cont = %s\n", buffer);
	str_buff = buffer_preproc(buffer, &find_enter, &sbf);
	if (!str_buff)
	{
//		printf("return NULL 2\n");
		return (NULL);
	}
//	printf("BP 1\n");
//	printf("buffer cont a = %s\n", buffer);
//	printf("str_buff cont a = %s\n", str_buff);
//	printf("BP 1\n");
//	return (str_buff);
	while(!buffer[BUFFER_SIZE] && !find_enter)
	{
//		printf("buffer 1 = %s\n", buffer);
//		printf("BP 2\n");
		r = read(fd, buffer, BUFFER_SIZE);
		printf("r = %d\n", r);
		printf("buffer 1 = %s\n", buffer);
		if(!r || r == -1)
		{
			if (r == -1)
			{
				free(str_buff);
				return (NULL);
			}

			if (buffer[0] && !r)
			{
				buffer[BUFFER_SIZE] = '!';
				return (str_buff);
			}
//			test = (char *) malloc (BUFFER_SIZE);
//			ft_memcpy(test, buffer, 5);
//			test[5] = '\0';
//			printf("str = %s\n", test);
//			printf("BP 1\n");

//			printf("buffer 2 = %s\n", buffer);

			free(str_buff);
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
//		printf("realloc\n");
//		printf("find_enter = %p\n", find_enter);
//		printf("str_buff (ar) = %s\n", str_buff);
//		printf("BP 2\n");
//		printf("find_enter = %p\n", find_enter);

		//i++;
	}
//	printf("BP 3\n");
	find_enter = ft_memchr(str_buff, '\n', BUFFER_SIZE * (i + 1) + sbf);
//	printf("find_enter2 = %p\n", find_enter);
	if(*find_enter != buffer[0])
		*(find_enter + 1) = '\0';



//	printf("BP 3\n");
//	printf("str_buff = %s\n", str_buff);
//	printf("buffer cont 2 = %s\n", buffer);



	return (str_buff);
}
