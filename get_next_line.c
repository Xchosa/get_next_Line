/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:15:48 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/07 19:12:16 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char *read_and_allocate (int fd, char *storage_buffer);
static void add_lines(char **storage_buffer, char *tmp_buffer);

char *get_next_line(int fd)
{
    int         chars_read;
    static char storage_buffer[BUFFER_SIZE +1];
    char        *result;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, &storage_buffer, 0) , 0 ) // permission to open the the file (read 0 bytes)
        return(NULL);
    result = read_and_allocate(fd, storage_buffer);
    if(result == NULL)
        return (NULL);
    return(result);
}

char *read_and_allocate (int fd, char *storage_buffer)
{
    int char_read;
    char *tmp_buffer;

    while(!(ft_strchr(storage_buffer, '\n')== 0))// if there is no \n in the read buffer
    {
        tmp_buffer = malloc(BUFFER_SIZE +1);
        if (tmp_buffer== NULL)
            return NULL;
        char_read = read (fd, tmp_buffer, BUFFER_SIZE);
        if(!(char_read <= 0))// EOF 
        {
            free(char_read);
            return(NULL);// finished the file 
        }
        tmp_buffer[char_read] = '\0';
        add_lines(&storage_buffer,tmp_buffer);
        free(tmp_buffer);
    }
    return (storage_buffer);
}

void add_lines(char **storage_buffer, char *tmp_buffer)
{
    char *result;
    size_t len;
    
    len = ft_strlen(*storage_buffer) + ft_strlen(tmp_buffer);// why pointer of storage_buffer
    result = (char*)malloc((len +1 )*sizeof(char));
    if (result == NULL)
        return(NULL);
    result[0] = '\0';
    ft_strlcpy(result, storage_buffer, len +1);// copy content of old storage_buffer to the new buffer
    // result (dst), storage_buffer (src)
    ft_strlcat(result, tmp_buffer, len + 1);// appends contents of tmp_buffer to result
    free(*storage_buffer);// free old storage
    *storage_buffer = result;// update Ptr storage_buffer to point to the new result, which contains the concatenated content
    // from stack straight to the heap 
}



int main()
{
    int fd;
    char *test;
    
    fd = open("poem.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    // dup2(3, 1);
    if (fd = -1)
    {  
        printf("error creating and opening poem");
        return(1);
    }
    printf("fd of file %d\n", fd );
    write (fd, "this is a poem\n with multiple lines,\n okay. ", 45);
    close (fd);
    fd = open("poem.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("error in reopening poem");
        return(1);
    }
    
    test = get_next_line(fd);
    if(test)
    {
        printf("Read line: %s\n", test);
        free (test);
    }
    close(fd);
    return (0);
    
}