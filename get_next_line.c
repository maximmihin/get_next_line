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

char 	*buffer_preproc(char *buffer, int *len_str)
{
	char 		*str;
	char 		*find_enter;

//	printf("buffer (pp-s) = %s\n", buffer);
//	printf("c = %c\n", buffer[BUFFER_SIZE]);
	if (buffer[BUFFER_SIZE] == '!')
	{
//		printf("C 1\n");
		return (NULL);
	}
	//1 and 2
	find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (!*buffer || find_enter == &buffer[BUFFER_SIZE - 1])
	{
//		printf("CASE 1\n");
		ft_bzero(buffer, BUFFER_SIZE + 1);
//		printf("str = |%s|\n", str);
		find_enter = NULL;
//		printf("*** malloc 1 ****\n");
		str = (char *) malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		ft_bzero(str, BUFFER_SIZE);
		return (str);
	}

	//3
//	printf("CASE 3\n");
	*len_str = &buffer[BUFFER_SIZE] - find_enter - 1;
//	printf("*len_str = %d\n", *len_str/* + BUFFER_SIZE + 1*/);
//	printf("*** malloc 2 ****\n");
	str = (char *) malloc(*len_str + BUFFER_SIZE + 1);
	if (!str)
	{
//		printf("return NULL 1\n");
		return (NULL);
	}
	ft_bzero(str, *len_str + BUFFER_SIZE + 1);

	ft_memcpy(str, find_enter + 1, *len_str);
//	printf("str = %s\n", str);

	find_enter = (NULL);

	//4
	find_enter = (char *)ft_memchr(str, '\n', BUFFER_SIZE);
	if (find_enter)
	{
//		printf("CASE 4\n");
		find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
		*find_enter = 's';
	}
	else
		ft_bzero(buffer, BUFFER_SIZE + 1);

//	printf("buffer (pp-e) = %s\n", buffer);
//	printf("return str (preproc)\n");
	return (str);
}



char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char		*str_buff;
	int 		sbf; //start buffer len;
	int			i;
	int			r;

	char 		*find_enter;

//	printf("\n*** Start gnl ***\n");
	sbf = 0;
	i = 0;


//	printf("buffer 1 = |%s|\n", buffer);
	str_buff = buffer_preproc(buffer, &sbf);
	if (!str_buff)
		return (NULL);
//	printf("buffer 2 = |%s|\n", buffer);


	while (!buffer[BUFFER_SIZE])
	{
//		printf("str_buff b = |%s|\n", str_buff);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r > 0)
		{
			ft_memcpy(&str_buff[BUFFER_SIZE * i + sbf], buffer, r);
//			printf("buffer = |%s|\n", buffer);
//			printf("str_buff a = |%s|\n", str_buff);
//			printf("r = %d\n", r);
			if (r < BUFFER_SIZE)
			{
//				printf("BP 3\n");
//				buffer[BUFFER_SIZE] = '!';
//				buffer[r] = '\n';
				if (ft_memchr(buffer, '\n', BUFFER_SIZE))
				{
//					printf("BP 4\n");
					find_enter = ft_memchr(str_buff, '\n',
										   BUFFER_SIZE * i + sbf	+ 1);
					*(find_enter + 1) = '\0';

					return (str_buff);
				}


			}

			i++;
			if (ft_memchr(buffer, '\n', BUFFER_SIZE))
			{
//				printf("BP 4\n");
				find_enter = ft_memchr(str_buff, '\n',
									   BUFFER_SIZE * i + sbf	+ 1);
				*(find_enter + 1) = '\0';

				return (str_buff);
			}


//			printf("*** realloc ****\n");
//			printf("oldlen = %d\n", BUFFER_SIZE * i + sbf + 1);
//			printf("newlen = %d\n", BUFFER_SIZE * (i + 1) + sbf + 1);

			str_buff = ft_realloc(str_buff, BUFFER_SIZE * i + sbf + 1,
								  BUFFER_SIZE * (i + 1) + sbf + 1);
//			str_buff = realloc(str_buff,BUFFER_SIZE * (i + 1) + sbf + 1);
			if (!str_buff)
				return (NULL);

			ft_bzero(buffer, BUFFER_SIZE);

		}
		else
		{
			if (r == -1)
			{
//				printf("BP 1\n");
//				printf("free 1\n");
				free(str_buff);
				return (NULL);
			}
			if (r == 0)
			{
				buffer[0] = '\0';
				buffer[BUFFER_SIZE] = '!';
				if (*str_buff)
				{
//					printf("BP 555\n");
					return (str_buff);
				}
//				printf("BP 2\n");
//				printf("free 2\n");
				free(str_buff);
				return (NULL);

			}
		}







	}


//	ret



	printf("BP 666\n");
	return (str_buff);
}
