/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:16:55 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/10 15:07:43 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	char	*cpys1;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	cpys1 = (char *)malloc((len + 1) * (sizeof(char)));
	if (cpys1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cpys1[i] = s1[i];
		i++;
	}
	cpys1[i] = '\0';
	return (cpys1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstsize == 0)
		return (srclen);
	if (dstlen >= dstsize)
	{
		return (dstsize + srclen);
	}
	while ((dstlen + i < dstsize - 1) && (src[i] != '\0'))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	strlen_s1;
	size_t	strlen_s2;

	strlen_s1 = ft_strlen(s1);
	strlen_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	newstr = (char *)malloc(((strlen_s1 + strlen_s2 + 1) * (sizeof(char))));
	if (newstr == NULL)
		return (NULL);
	while (i < strlen_s1)
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < strlen_s2)
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
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
