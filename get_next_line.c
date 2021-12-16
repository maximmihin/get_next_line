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
/*
int	init_str_buf(char **str_buff, size_t begin_buff_size, char *buffer)
{
	int have_str_buff;

	if (!begin_buff_size)
	{
		*str_buff = (char *)malloc(BUFFER_SIZE + 1);
		if (!*str_buff)
			return (0);
	}
	else
	{
		*str_buff = (char *)malloc(BUFFER_SIZE + begin_buff_size + 1);
		if (!*str_buff)
			return (0);

		printf("str_buff = |%s|\n", *str_buff);
		printf("buffer contain = |%s|\n", buffer);
		printf("begin_buff_size = %lu\n", begin_buff_size);

		ft_memcpy(*str_buff, buffer, begin_buff_size);

		printf("str_buff = |%s|\n", *str_buff);

	}
	printf("made str_buf\n");
	printf("str_buff = |%s|\n", *str_buff);

	have_str_buff = 1;
	return (have_str_buff);
}







char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char 		*str_ret;
	char		*str_buff;
	int			i;
	int			have_str_buff;
	char 		*find_end;
	char 		*find_enter;
	size_t		len_buff_str;
	size_t		len_str;
	size_t		begin_buff_size;

	printf("*** start gnl ***\n");

	i = 0;
	find_end = NULL;
	find_enter = NULL;

	begin_buff_size = ft_strlen(buffer);
	printf("0 begin_buff_size = %lu\n", begin_buff_size);
	printf("buffer contain = |%s|\n", buffer);
	have_str_buff = init_str_buf(&str_buff, begin_buff_size, buffer);
	if (!have_str_buff)
		return (NULL);
	printf("2 str_buff = |%s|\n", str_buff);


//	find_end = (char *)ft_memchr(buffer, '\0', BUFFER_SIZE);
//	printf("* find_end = %p\n", find_end);
//	find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
//	printf("* find_enter = %p\n", find_enter);

	while(!find_enter && !find_end)
	{
		read(fd, buffer, BUFFER_SIZE);
		printf("buffer1 = |%s|\n", buffer);

		find_end = (char *)ft_memchr(buffer, '\0', BUFFER_SIZE);
		printf("* find_end = %p\n", find_end);
		find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);


		if (i == 0)//first iter
		{
			printf("i == 0\n");
			ft_memcpy(&str_buff[begin_buff_size], buffer, BUFFER_SIZE + 1);
		}
		else //next iter
		{
			str_buff = ft_realloc(str_buff, BUFFER_SIZE * i + 1 + begin_buff_size,
								  BUFFER_SIZE * (i + 1) + 1 + begin_buff_size);

			ft_memcpy(&str_buff[BUFFER_SIZE * i + begin_buff_size], buffer, BUFFER_SIZE + 1);
			printf("str_buff2 = |%s|\n", str_buff);
		}
		i++;
		printf("-----------------------------\n");
	}





	if (find_end)
		return (NULL);
	//don't forget '\0' in an and (1 line in file)
	len_str = (char *)ft_memchr(str_buff, '\n', BUFFER_SIZE * i + begin_buff_size) - str_buff;

	printf("len_str = %lu\n", len_str);

	str_ret = (char *) malloc(len_str + 1);

	ft_memcpy(str_ret, str_buff, len_str);
	str_ret[len_str] = '\0';

	printf("buffer3 = |%s|\n", buffer);

	len_buff_str = (char *) ft_memchr(buffer, '\n', BUFFER_SIZE) - buffer;
	ft_memcpy(buffer, &buffer[len_buff_str + 1], BUFFER_SIZE - len_buff_str);
	buffer[BUFFER_SIZE - len_buff_str] = '\0';

	printf("buffer4 (fin) = |%s|\n", buffer);


	free(str_buff);

	printf("str_ret len = %lu\n", ft_strlen(str_ret));
	printf("str_ret = |%s|\n", str_ret);
	printf("*****************************************\n");


	//don't forget free all malloc!!!
	return (str_ret);
}
*/

void	find(char **find_enter, char *some_buffer, size_t len)
{
	char *find_end;

	find_end = NULL;

	*find_enter = (char *)ft_memchr(some_buffer, '\n', len);
	printf("@@@@@@@@@@@@@@@@@@@@@@\n");

	find_end = ft_memchr(some_buffer, '\0', len);
	printf("find_end = %p\n", find_end);
	if(find_end)
	{
		printf("@ @@@ @\n");
		some_buffer[len] = '!';
	}
}



char 	*buffer_preproc(char *buffer, char **find_enter, int *len_str)
{
	char 		*str;
	//int 		len_str;
	char		c;

	if (buffer[BUFFER_SIZE] == '!')
		return	(NULL);


//	if (!*buffer)
//		return (str);


	//1 and 2
	//find(find_enter, buffer, BUFFER_SIZE);
	printf("find_enter 1 = %p\n", *find_enter);
	*find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
	printf("find_enter 2 = %p\n", *find_enter);
	if (!*buffer || *find_enter == &buffer[BUFFER_SIZE - 1])
	{
		printf("CASE 1\n");
		*find_enter = NULL;
		str = (char *) malloc(BUFFER_SIZE + 1);
		return (str);
	}

	//3
	if (*find_enter)
	{
		printf("CASE 3\n");
		*len_str = &buffer[BUFFER_SIZE] - *find_enter - 1;
		printf("len_str = %d\n", *len_str);
		str = (char *) malloc(*len_str + BUFFER_SIZE + 1);
		ft_memcpy(str, *find_enter + 1, *len_str);

		c = *(*find_enter + 1);
		printf("**str = %c\n", c);

		*find_enter = (NULL);
	}

	//4
//	find(find_enter, &str, *len_str);
	*find_enter = (char *)ft_memchr(str, '\n', BUFFER_SIZE);
	if (*find_enter)
	{
		printf("CASE 4\n");
		//find(find_enter, buffer, len_str);
		*find_enter = (char *)ft_memchr(buffer, '\n', BUFFER_SIZE);
		**find_enter = 's';
	}

	return (str);
}



char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*find_enter;
	char		*str_buff;
	int 		sbf; //start buffer len;
	int			i;

	printf("*** Start gnl ***\n");
	sbf = 0;
	i = 0;

	printf("buffer cont b = %s\n", buffer);
	//printf("str_buff cont b = %s\n", str_buff);
	str_buff = buffer_preproc(buffer, &find_enter, &sbf);
	if (!str_buff)
		return (NULL);
	printf("buffer cont a = %s\n", buffer);
	printf("str_buff cont a = %s\n", str_buff);
	printf("BP 1\n");

	while(!buffer[BUFFER_SIZE] && !find_enter)
	{

		read(fd, buffer, BUFFER_SIZE);



		find (&find_enter, buffer, BUFFER_SIZE);
		printf("buffer = %s\n", buffer);
		printf("* buffer[BUFFER_SIZE] = %c\n", buffer[BUFFER_SIZE]);



		ft_memcpy(&str_buff[BUFFER_SIZE * i + sbf], buffer, BUFFER_SIZE);
		//to del
		//str_buff[BUFFER_SIZE * i + 1] = '\0';
		printf("str_buff = %s\n", str_buff);

		i++;
		//here bug in len. First time oldlen != B_S * i + 1 + sbf)
		str_buff = ft_realloc (str_buff, BUFFER_SIZE * i + 1 + sbf,
							  BUFFER_SIZE * (i + 1) + 1 + sbf);
		printf("str_buff (ar) = %s\n", str_buff);
		printf("BP 2\n");
		printf("find_enter = %p\n", find_enter);

		//i++;
	}

	find_enter = ft_memchr(str_buff, '\n', BUFFER_SIZE * (i + 1) + sbf);
	printf("find_enter2 = %p\n", find_enter);
	*find_enter = '\0';



	printf("BP 3\n");
	printf("str_buff = %s\n", str_buff);




	return (str_buff);
}
