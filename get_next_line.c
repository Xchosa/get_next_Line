/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/11 11:02:34 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char	*read_and_allocate(int fd, char *storage_buffer);
static void	add_lines(char **storage_buffer, char *tmp_buffer);
static char *seperate_rest(char *storage_buffer);

char	*get_next_line(int fd)
{
	int			chars_read;
	static char	storage_buffer[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	if (result == NULL)
		return (NULL);
	return (result);
}
// strchr gives the points to the first position of \n 
// memmove copies in  The memmove() function copies len bytes from string 
	// 	src to string dst.  The two strings may overlap; 
	// 	the copy is always done
    //  in a non-destructive manner.
ft_memmove(storage_buffer, (ft_strchr(storage_buffer,'\n')), (ft_strlen(storage_buffer)) )

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

	// test = get_next_line(fd);
	// if (test)
	// {
	// 	printf("Read line: %s\n", test);
	// 	while ;
	// }
	while(1)
	{
		test = get_next_line(fd);
		if(!test)
		{
			break;
		}
		printf("%s", test);
	}
	free(test);
	close(fd);
	return (0);
}