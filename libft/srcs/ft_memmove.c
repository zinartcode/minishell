/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 16:05:58 by azinnatu          #+#    #+#             */
/*   Updated: 2017/07/26 16:07:29 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s < d)
	{
		s = s + len;
		d = d + len;
		while (len-- > 0)
		{
			*(--d) = *(--s);
		}
	}
	else
	{
		while (len-- > 0)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
