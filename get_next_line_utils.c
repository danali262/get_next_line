/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 10:22:35 by danali        #+#    #+#                 */
/*   Updated: 2020/11/16 15:28:28 by dgiannop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	s = NULL;
	d = NULL;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (dst);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
