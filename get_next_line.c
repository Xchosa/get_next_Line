/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/12 14:27:39 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int read_store(int fd, char **storage_buffer);
static char *next_line(char **storage_buffer);

char	*get_next_line(int fd)
{
	int		bytes_read;
	static char	*storage_buffer = NULL;
	char 	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	if(!storage_buffer)
		storage_buffer = ft_strdup(""); // malloc check

	bytes_read = read_store(fd, &storage_buffer);
	if (bytes_read < 0 )
		return ("error reading"); // free storgaebuffer
		// printf("strbuf1: %s\n", storage_buffer);
	if (bytes_read == 0)
	{
		if(storage_buffer[0] != '\0')
		{
			temp = storage_buffer;
			storage_buffer = NULL;// storage_buffer leeren, am ende der file 
			return (temp);
		}
		else 
			return NULL;
	}
	int len;
	char *line;
	int i;

	i = 0;
	
	// len = ft_strlen(ft_strchr(*storage_buffer, '\n' ));
	while(storage_buffer[i] != '\n')
	{
		i++;
	}
	i++;
	line = (char*)malloc((i +1 )* (sizeof(char)));
	ft_strlcpy(line, storage_buffer, i +1 );
	line [i] = '\0';
	storage_buffer += i;// memory content aerdern 
	// return(next_line(&storage_buffer));
	// 
	// printf("strbuf2: %s\n", line);
	return(line);
}
	// bytes die eingelsesen sind (bytes_read)
	// eingelesene chars in buffer
	// pointer to pointer to modify the original pointer, to update the
	//pointer to point to its new memmory. 
int read_store(int fd, char **storage_buffer) 
	{
		char		read_buffer[BUFFER_SIZE +1];
		char		*tmp_buffer;
		ssize_t 	bytes_read;
		
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return(-1);
		while (bytes_read > 0) // as long smth gets read
			{
				read_buffer[bytes_read] = '\0';
				tmp_buffer = ft_strjoin (*storage_buffer, read_buffer);
				if(!tmp_buffer)
					return(-1);
				// free(*storage_buffer);
				*storage_buffer = tmp_buffer; // copy all in storage buffer
				if (ft_strchr(tmp_buffer, '\n' ))
					{
						// storage_buffer = next_line(&tmp_buffer);// exit to handle n\lines
						// return(1);
				
						break;
					}
			bytes_read = read(fd,read_buffer, BUFFER_SIZE); // read next chars 		
			}
		return(bytes_read);
	}
	
// char *next_line(char **storage_buffer)// find length until n copy only this part 
// // and return this line. 
// {
// 	int len;
// 	char *line;
// 	int i;

// 	i = 0;
	
// 	// len = ft_strlen(ft_strchr(*storage_buffer, '\n' ));
// 	while(*storage_buffer[i] != '\n')
// 	{
// 		i++;
// 	}
// 	i++;
// 	line = (char*)malloc((i +1 )* (sizeof(char)));
// 	ft_strlcpy(line, *storage_buffer, i );
// 	line [i] = '\0';
// 	*storage_buffer += i;// memory content aerdern 
// 	return(line);// line with /n
// }


// 	// ft_memmove(tmp_buffer, (ft_strchr(buffer,'\n')), (ft_strlen(buffer)) );
// 	// return(storage_buffer = tmp_buffer);
// 	// to tmp_buffer , next letters of buffer(with the \n) gets added
// }
// strchr gives the points to the first position of \n 
// memmove copies in  The memmove() function copies len bytes from string 
	// 	src to string dst.  The two strings may overlap; 
	// 	the copy is always done
    //  in a non-destructive manner.

int	main(void)
{
	int fd;
	char *test;
	char *test2;

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

	test = get_next_line(fd);
	// test2 = get_next_line(fd);
	// printf("first 1 %s", test);
	// printf("first 2 %s", test2);
	// printf("first 1 %s", test);
	while(1)
	{
		test = get_next_line(fd);
		if (!test)
			break;
		printf("first 1 %s", test);
		
	}

	// }
	free(test);
	close(fd);
	return (0);
}