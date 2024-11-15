/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/15 14:28:05 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char* ft_createline(char *line);

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	static char	buffer[BUFFER_SIZE+1];
	char 		*line; // output
	char		*tmp_buffer;
	size_t		i;
	size_t		j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin("", buffer);
	if(!line)
		return(NULL);
	// hat nichts geaendert
	// line = tmp_buffer;
	// free(tmp_buffer);
	while(!ft_strchr(buffer, '\n') )// buffer[0] is not empty
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read == 0)
		{
			if (buffer[0] == 0)
				return (free(line), NULL);
			ft_bzero(buffer, BUFFER_SIZE +1);
			// tmp_buffer = line;
			return(line);
		}
		else if (bytes_read < 0)
		{
			ft_bzero(buffer, BUFFER_SIZE +1);
			return (free(line), line = NULL, NULL);
		}
		buffer[bytes_read] = '\0';
		tmp_buffer = ft_strjoin(line, buffer);
		if (!tmp_buffer)
			return(free(line), line = NULL, NULL);
		free(line);
		line = tmp_buffer;

	}
	tmp_buffer = ft_createline(line);
	if (!tmp_buffer)
		return (NULL);
	free(line);
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
	return(tmp_buffer);
}
char *ft_createline(char *line)
{
	char *newline;
	ssize_t i;
	i = 0;
	while(line[i]!= '\n')
	{
		i++;
	} 
	i++;
	newline = (char*) malloc (i * sizeof(char) + 1);
	if(!newline)
		return(free(line), line = NULL, NULL);
	ft_memmove(newline, line, i );
	newline[i] = '\0';
	return(newline);
}
	

	// wenn wir new line haben dann returnen und buffer updaten. 

// int	main(void)
// {
// 	int fd;
// 	char *test = NULL;
	
// 	fd = open("poem.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("error in reopening poem");
// 		return (1);
// 	}

// 	while(1)
// 	{
// 		test = get_next_line(fd);
// 		if (!test)
// 			break;
// 		printf("%s", test);
// 	}

// 	// free(test);
// 	close(fd);
// 	return (0);
// }