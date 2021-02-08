/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 09:28:26 by danali        #+#    #+#                 */
/*   Updated: 2020/11/19 12:18:04 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD 1024

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_gnl
{
	int		initialized;
	int		end_of_bytes_read;
	int		offset;
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*stored;
	int		stored_length;
}				t_gnl;

int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
