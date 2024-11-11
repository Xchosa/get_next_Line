/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/11 14:56:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"


char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	static char	*storage_buffer = NULL;
	char		buffer[BUFFER_SIZE +1];
	char		*tmp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	if(!storage_buffer)
		storage_buffer = ft_strdup("");
	bytes_read = read(fd,buffer, BUFFER_SIZE); 
	// bytes die eingelsesen sind (bytes_read)
	// eingelesene chars in buffer
	while (bytes_read > 0 ||(!ft_strchr(buffer, '\n' )))// as long as no \n found (not yet copied)
		{
			buffer[bytes_read] = '\0';
			
			tmp_buffer = ft_strjoin (storage_buffer, buffer);// first  NULL + Hal = tmp_buffer(HAL)
			// sec Call; hal + lo 
			if (!tmp_buffer)
			{
			free(storage_buffer);
			*buffer = tmp_buffer; // buffer points now to L of Hal 
			}
			bytes_read = (fd,buffer, BUFFER_SIZE); // read next chars 
		}
	ft_memmove(tmp_buffer, (ft_strchr(buffer,'\n')), (ft_strlen(buffer)) );
	return(storage_buffer = tmp_buffer);
	// to tmp_buffer , next letters of buffer(with the \n) gets added
}
// strchr gives the points to the first position of \n 
// memmove copies in  The memmove() function copies len bytes from string 
	// 	src to string dst.  The two strings may overlap; 
	// 	the copy is always done
    //  in a non-destructive manner.

int	main(void)
{
	int fd;
	char *test;

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
	// if (!test)
	// {
		printf("Read line: %s\n", test);
	// 	while ;
	// }
	// while(1)
	// {
	// 	test = get_next_line(fd);
	// 	if(!test)
	// 	{
	// 		break;
	// 	}
	// 	printf("%s", test);
	// }
	free(test);
	close(fd);
	return (0);
}