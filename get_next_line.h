/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:11:16 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/14 11:37:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# include <stdio.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);

#endif

// -D BUFFER_SIZE=n