/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/06 10:16:50 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int         bytes_read;
    static char *storage_buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    storage_buffer = read_and_allocate(fd, storage_buffer);
    if(storage_buffer = NULL)
        return (NULL);
    
    // bytes_read = read(fd, storage_buffer, 3);

    // if (bytes_read < 0)
    // {
    //     free(storage_buffer);
    //     storage_buffer = NULL;
    //     return (NULL);
    // }
    return(storage_buffer);
}



char read_and_allocate (int fd, char *storage_buffer)
{
    char *tmp_buffer;
    char str_line;
    int new_line;
    
    if (storage_buffer = NULL)
        storage_buffer = ft_calloc(1,1);
    
    tmp_buffer = ft_calloc(BUFFER_SIZE +1 , (sizeof(char)));
    new_line = search_new_line()
    str_line = read(fd,tmp_buffer,BUFFER_SIZE);
}

int search_new_line(char *str)
{
    int i;
    while (str[i] != "\0")
    {
        if (str[i] == "\n")
            return (i);
        i++;
    }
    return (-1);
}

int main(void)
{
    int fd;
    char *next_line;
    int count; // testing

    count = 0;

    fd = open("poem.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while(1)
    {
        next_line = get_next_line(fd);
        count++;
        printf("%d: %s\n", count, next_line );
    //    free(next_line);
        if ((next_line = get_next_line(fd)) != NULL)
         break;
    }
    close(fd);
    return(0);
}