/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:16:55 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/06 10:16:30 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*prt;
	size_t			i;

	prt = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		prt[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = count * size;
	ptr = malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, i);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	b;

	b = (char)c;
	while (*s)
	{
		if (b == *s)
		{
			return ((char *)s);
		}
		s++;
	}
	if (b == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	b;

	b = (char)c;
	len = ft_strlen(s);
	if (b == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		if (*(s + len - 1) == b)
			return ((char *)s + len - 1);
		len--;
	}
	return (NULL);
}