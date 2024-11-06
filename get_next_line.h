/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:11:16 by poverbec          #+#    #+#             */
/*   Updated: 2024/11/05 14:38:22 by poverbec         ###   ########.fr       */
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

#endif

// -D BUFFER_SIZE=n