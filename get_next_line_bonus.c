/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 09:13:03 by danali        #+#    #+#                 */
/*   Updated: 2020/11/19 12:18:37 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		initialize_struct(t_gnl *current_file)
{
	if (!(current_file->initialized == 1))
	{
		current_file->initialized = 1;
		current_file->end_of_bytes_read = 0;
		current_file->offset = BUFFER_SIZE;
		current_file->stored = NULL;
		current_file->stored_length = 0;
	}
}

static char		*store_line(t_gnl *current_file, int flag)
{
	char	c;
	char	*new;

	c = current_file->buffer[current_file->offset];
	current_file->offset += 1;
	new = malloc((current_file->stored_length + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	if (current_file->stored != NULL)
	{
		ft_memcpy(new, current_file->stored, current_file->stored_length);
		free(current_file->stored);
	}
	if (c == '\n' || flag == 1)
	{
		new[current_file->stored_length] = '\0';
		current_file->stored = NULL;
		current_file->stored_length = 0;
		return (new);
	}
	new[current_file->stored_length] = c;
	current_file->stored_length += 1;
	current_file->stored = new;
	return (NULL);
}

static int		process_line(t_gnl *current_file, char **line)
{
	int		flag;
	char	*new_line;

	while (current_file->offset + 1 < BUFFER_SIZE + 1)
	{
		if (current_file->offset < current_file->bytes_read)
			flag = 0;
		else
			flag = 1;
		new_line = store_line(current_file, flag);
		if (new_line != NULL)
		{
			if (flag == 1)
				current_file->end_of_bytes_read = 1;
			*line = new_line;
			return (1);
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	files[MAX_FD];
	t_gnl			*current_file;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	*line = NULL;
	current_file = &files[fd];
	initialize_struct(current_file);
	while (1)
	{
		if (current_file->offset == BUFFER_SIZE)
		{
			current_file->bytes_read = read(fd, current_file->buffer,
			BUFFER_SIZE);
			current_file->offset = 0;
		}
		if (current_file->bytes_read == -1)
			return (-1);
		if (process_line(current_file, line))
		{
			if (!current_file->bytes_read || current_file->end_of_bytes_read)
				return (0);
			return (1);
		}
	}
}
