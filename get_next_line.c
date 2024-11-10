/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/10 12:36:10 by poverbec         ###   ########.fr       */
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
	result = read_and_allocate(fd, storage_buffer);
	if (result == NULL)
		return (NULL);
	return (seperate_rest(storage_buffer));
}

char	*read_and_allocate(int fd, char *storage_buffer)
{
	int		char_read;
	char	*tmp_buffer;

	while ((ft_strchr(storage_buffer, '\n') == 0))
	// if there is no \n in the read buffer
	{
		tmp_buffer = malloc(BUFFER_SIZE + 1);
		if (tmp_buffer == NULL)
			return (NULL);
		char_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if ((char_read <= 0)) // EOF
		{
			free(tmp_buffer);
			return (NULL); // finished the file
	}	
		tmp_buffer[char_read] = '\0';
		add_lines(&storage_buffer, tmp_buffer);
		free(tmp_buffer);
	}

	return (seperate_rest(storage_buffer));
}

void	add_lines(char **storage_buffer, char *tmp_buffer)
{
	char	*result;
	size_t	len;

	len = ft_strlen(*storage_buffer) + ft_strlen(tmp_buffer);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return ;
	result[0] = '\0';
	ft_strlcpy(result, *storage_buffer, len + 1);
	ft_strlcat(result, tmp_buffer, len + 1);
		// appends contents of tmp_buffer to result
	// result = seperate_rest(result);
	*storage_buffer = result; 
	// result hat gerade alles soll aber nur 
	//   eine zeile zuruckgeben. 
	// printf("test of strlcat %s , hier ", result);
		// update Ptr storage_buffer to point to the new result,
		// which contains the concatenated content
	// from stack straight to the heap
}

char *seperate_rest(char *storage_buffer)
{
	char *rest;
	int i;
	size_t len_of_leftover_poem;
	
	len_of_leftover_poem = 0;
	i = 0;
	while(storage_buffer[i] != '\n' && storage_buffer[i] != '\0')
		i++;
	if(storage_buffer[i] == '\n')
		i++;
	rest = (char*)malloc((i +1)* sizeof(char));
	if (rest == NULL)
		return (NULL);
	ft_strlcpy(rest, storage_buffer, i);
	rest[i] = '\0';
	
	printf("test of rest %s , \n hier ", rest);
	
	while(storage_buffer[i + len_of_leftover_poem] != '\0')
	{
		storage_buffer[len_of_leftover_poem] = storage_buffer[i];
		len_of_leftover_poem++;
	}
	storage_buffer[len_of_leftover_poem] = '\0';
	printf("test of rest %s , \n hier ", storage_buffer);
	return(rest);
}

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