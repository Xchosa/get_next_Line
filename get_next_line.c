/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/14 16:39:14 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char* ft_createline(char *line);

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	buffer[BUFFER_SIZE+1];
	char 		*line; // output
	char		*tmp_buffer;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	line = ft_strjoin("", buffer);
	//  neuen string mit dem buffer (dem rest vorne dran) 
	while(!ft_strchr(buffer, '\n') )// buffer[0] is not empty
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == 0)
		{
			buffer[0]= '\0';
			if (!line && !*line )
				{
				free(line);
				return (NULL);
				}
			return(line);
		}
		else if (bytes_read < 0)
			return (NULL);
		line = ft_strjoin(line, buffer);
	}
	if (!*buffer)
		return(free(line), line);// set line to zero
	line = ft_createline(line);
	i = 0;
	while(buffer[i] != '\n' && buffer[i])
		i++;
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i + 1];
		j++;
		i++;
	}
	buffer[j] = '\0';
	return(line);
}
char *ft_createline(char *line)
{
	char *newline;
	size_t i;
	i = 0;
	while(line[i]!= '\n')
	{
		i++;
	}
	i++; 
	
	newline = (char*) malloc (i * sizeof(char));
	ft_memmove(newline, line, i );
	newline[i] = '\0';
	
	return(newline);
}
	

	// wenn wir new line haben dann returnen und buffer updaten. 

int	main(void)
{
	int fd;
	char *test;
	char *test2;
	char *test3;
	char *test4;

	// fd = open("poem.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	// // dup2(3, 1);
	// if (fd == -1)
	// {
	// 	printf("error creating and opening poem");
	// 	return (1);
	// }
	// printf("fd of file %d\n", fd);
	// write(fd, "this is a poem\n with multiple lines,\n okay. ", 45);
	// close(fd);



	fd = open("poem.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error in reopening poem");
		return (1);
	}

	// test = get_next_line(fd);
	// printf(" %s", test);
	// test2 = get_next_line(fd);
	// printf(" %s", test2);
	// test3 = get_next_line(fd);
	// printf(" %s", test3);
	// test4 = get_next_line(fd);
	// printf(" %s", test4);
	while(1)
	{
		test = get_next_line(fd);
		if (!test)
			break;
		printf(" %s", test);
	}

	// }
	free(test);
	close(fd);
	return (0);
}