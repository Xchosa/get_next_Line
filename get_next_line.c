/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/18 11:31:40 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

// nicht pushen. eigens backup funktioniert
// pointer in read_store noch falsch , wann &
// last copilot call explain why **line 
static char* ft_createline(char *line);
static int read_store(char *buffer, char **line, int fd, int flag);
static void move_buffer_forward(char *buffer);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE+1];
	char 		*line;
	char		*tmp_buffer;
	int			flag;

	flag = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin("", buffer);
	if(!line)
		return(NULL);
	if (!ft_strchr(buffer, '\n'))
		if (read_store(buffer, &line,fd, flag) < 0)
			return (NULL);
	 if (flag == 1)
	 	return (line);

	tmp_buffer = ft_createline(line);
	if (!tmp_buffer)
		return (free(line), NULL);
	free(line);
	move_buffer_forward(buffer);
	return(tmp_buffer);
}

static int read_store(char *buffer, char **line, int fd, int flag)
{
	ssize_t bytes_read;
	char	*tmp_buffer;
	
		while(!ft_strchr(buffer, '\n'))
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if(bytes_read == 0)
			{
				if (buffer[0] == 0)
					return (0);
					return(ft_bzero(buffer, BUFFER_SIZE +1), flag = 1 , 0);// should return directly line. 
			}
			else if (bytes_read < 0)
			{
				ft_bzero(buffer, BUFFER_SIZE +1);
				return (free(*line), line = NULL, -1);
			}
			buffer[bytes_read] = '\0';
			tmp_buffer = ft_strjoin(*line, buffer);
			if (!tmp_buffer)
				return(free(line), line = NULL, -1);
			free(*line);
			*line = tmp_buffer;
		}
	return(0);
}


char *ft_createline(char *line)
{
	char *newline;
	ssize_t i;
	i = 0;
	while(line[i]!= '\n' )
		i++;
	// 	if (line [i] == '\n')
	// 		break ;
	// while()
	i++;
	newline = (char*) malloc (i * sizeof(char) + 1);
	if(!newline)
		return(free(line), line = NULL, NULL);
	ft_memmove(newline, line, i );
	newline[i] = '\0';
	return(newline);
}
static void move_buffer_forward(char *buffer)
{
	size_t i;
	size_t j;
	
	i = 0;
	j = 0;
	while(buffer[i] != '\n' && buffer[i])
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i + 1];
		j++;
		i++;
	}
	buffer[j] = '\0';
}
	

	// wenn wir new line haben dann returnen und buffer updaten. 

int	main(void)
{
	int fd;
	char *test = NULL;
	
	fd = open("poem.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error in reopening poem");
		return (1);
	}

	while(1)
	{
		test = get_next_line(fd);
		if (!test)
			break;
		printf("%s", test);
	}

	free(test);
	close(fd);
	return (0);
}