/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: danali <danali@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 10:22:35 by danali        #+#    #+#                 */
/*   Updated: 2020/11/19 12:18:54 by danali        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
