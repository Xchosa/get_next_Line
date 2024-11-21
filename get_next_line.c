/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/21 14:56:15 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char	*ft_createline(char *line);
static int	read_store(char *buffer, char **line, int fd, int *flag);
static void	move_buffer_forward(char *buffer);
static int	handle_buffer_zero(char **buffer, int bytes_read,
				char **tmp_buffer, char **line);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp_buffer;
	int			flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin("", buffer);
	if (!line)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		if (read_store(buffer, &line, fd, &flag) < 0)
			return (NULL);
	if (flag == 1)
		return (line);
	if (flag == 2)
		return (NULL);
	tmp_buffer = ft_createline(line);
	if (!tmp_buffer)
		return (NULL);
	free(line);
	move_buffer_forward(buffer);
	return (tmp_buffer);
}

static int	read_store(char *buffer, char **line, int fd, int *flag)
{
	ssize_t	bytes_read;
	char	*tmp_buffer;

	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (buffer[0] == 0)
				return (free(*line), *flag = 2, 0);
			if (handle_buffer_zero(&buffer, bytes_read, &tmp_buffer, line) < 0)
				return (-1);
			return (free(*line),*line = tmp_buffer, *flag = 1, 1);
		}
		if (bytes_read < 0)
			return (ft_bzero(buffer, BUFFER_SIZE + 1), free(*line), -1);
		buffer[bytes_read] = '\0';
		tmp_buffer = ft_strjoin(*line, buffer);
		if (!tmp_buffer)
			return (free(*line), -1);
		free(*line);
		*line = tmp_buffer;
	}
	return (0);
}

static int	handle_buffer_zero(char **buffer, int bytes_read,
		char **tmp_buffer, char **line)
{
	(*buffer)[bytes_read] = '\0';
	*tmp_buffer = ft_strjoin(*line, *buffer);
	if (!(*tmp_buffer))
		return (free(*line), -1);
	return (0);
}

char	*ft_createline(char *line)
{
	char	*newline;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	newline = (char *)malloc((i + 1) * sizeof(char));
	if (!newline)
		return (free(line), line = NULL, NULL);
	ft_memmove(newline, line, i);
	newline[i] = '\0';
	return (newline);
}

static void	move_buffer_forward(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	while (buffer[i])
	{
		buffer[j] = buffer[i + 1];
		j++;
		i++;
	}
	buffer[j] = '\0';
}

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

// 	free(test);
// 	close(fd);
// 	return (0);
// }