/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:48:55 by azinnatu          #+#    #+#             */
/*   Updated: 2017/07/26 15:48:57 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	while (len)
	{
		*((char*)dst) = *((char*)src);
		dst = (void*)((char*)dst + 1);
		src = (void*)((char*)src + 1);
		if ((char)(c) == *((char*)dst - 1))
		{
			return (dst);
		}
		len--;
	}
	return (NULL);
}
